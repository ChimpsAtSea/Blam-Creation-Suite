import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import project_setup
import sln
import util
import build_task_manager
from build_download import DownloadBuildTask
from build_extract import ExtractBuildTask
from build_extract import ExtractMSIBuildTask
from build_ninja import NinjaBuildTask
from build_gn import GNBuildTask
from build_yasm import YasmBuildTask
from build_ffmpeg import FFMpegBuildTask

util.async_start()

def download_extract_task(url, cache_filename, output_directory):
    download_filepath = os.path.join(os.environ['BCS_DOWNLOAD_CACHE'], cache_filename)
    download_task = DownloadBuildTask(url, download_filepath)
    extract_task = ExtractBuildTask(download_filepath, output_directory, [download_task])
    return extract_task

def download_extract_task_thirdparty(url, cache_filename, output_directory):
    return download_extract_task(url, cache_filename, os.path.join(util.bcs_third_party_dir, output_directory))

def download_extract_msi_task(url, cache_filename, output_directory):
    download_filepath = os.path.join(os.environ['BCS_DOWNLOAD_CACHE'], cache_filename)
    download_task = DownloadBuildTask(url, download_filepath)
    extract_task = ExtractMSIBuildTask(download_filepath, output_directory, [download_task])
    return extract_task

_7z_directory = os.path.join(util.bcs_third_party_dir, '7-Zip/7z2201-x64/Files/7-Zip')
_7z_task = download_extract_msi_task(
    'https://www.7-zip.org/a/7z2201-x64.msi',
    '7z2201-x64.msi',
    _7z_directory)
os.environ['_7Z_DIR'] = _7z_directory

ewdk_directory = os.path.join(util.bcs_third_party_dir, 'EWDK/EWDK_ni_release_svc_prod1_22621_220804-1759')
ewdk_task = download_extract_task(
    'https://software-static.download.prss.microsoft.com/dbazure/988969d5-f34g-4e03-ac9d-1f9786c66749/EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso',
    'EWDK_ni_release_svc_prod1_22621_220804-1759.iso',
    ewdk_directory)
os.environ['EWDK_DIR'] = ewdk_directory
util.ewdk_dir = ewdk_directory



busybox_task = DownloadBuildTask(
    'https://frippery.org/files/busybox/busybox64.exe', 
    os.path.join(util.bcs_third_party_dir, 'busybox/busybox64.exe'))

winpix3_task = download_extract_task_thirdparty(
    'https://globalcdn.nuget.org/packages/winpixeventruntime.1.0.220810001.nupkg',
    'winpixeventruntime.1.0.220810001.nupkg',
    'winpixeventruntime/1.0.220810001')

ninja_build_task = NinjaBuildTask()
gn_build_task = GNBuildTask([ninja_build_task])
yasm_build_task = YasmBuildTask([ninja_build_task])
ffmpeg_build_tasks = [
    FFMpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'static', [yasm_build_task]),
    FFMpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'shared', [yasm_build_task]),
    FFMpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'static', [yasm_build_task]),
    FFMpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'shared', [yasm_build_task]),
    FFMpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'static', [yasm_build_task]),
    FFMpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'shared', [yasm_build_task]),
]

while build_task_manager.BuildTaskManager.process_tasks():
    pass

print("Setting up GN Build Environment")
project_setup.gn_setup_build_environment()

print("Setting up GN Ninja Projects")
print(f"Generating {project_setup.get_num_configurations()} configurations")
project_setup.gn_generate_project_configurations()
global_targets = project_setup.parse_global_targets_list('//solution')

print("Setting up Visual Studio Projects")
solution = sln.Solution('Blam Creation Suite', 'solution/blamcreationsuite.sln')
project_setup.setup_solution_project_structure(solution, global_targets)
project_setup.sln_setup_cpp_default_properties_file()

for project in solution.projects:
    sln.write_project(solution, project)
sln.write_solution("solution/", solution)

util.async_end()
