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
from build_extract import ExtractTarfileBuildTask
from build_ninja import NinjaBuildTask
from build_gn import GNBuildTask
from build_yasm import YasmBuildTask
from build_ffmpeg import FFMpegBuildTask
from build_msys2 import MSYS2BuildTask
from build_assimp import AssimpBuildTask
from build_cmake import CMakeBuildTask
from build_download import download_extract_task

util.async_start()

_7z_directory = os.path.join(util.bcs_third_party_dir, '7-Zip/7z2201-x64/Files/7-Zip')
_7z_task = download_extract_task(ExtractMSIBuildTask,
    'https://www.7-zip.org/a/7z2201-x64.msi',
    '7z2201-x64.msi',
    _7z_directory)
os.environ['_7Z_DIR'] = _7z_directory
util._7z_dir = _7z_directory
util._7z_path = os.path.join(_7z_directory, "7z")

ewdk_directory = os.path.join(util.bcs_third_party_dir, 'EWDK/EWDK_ni_release_svc_prod1_22621_220804-1759')
ewdk_task = download_extract_task(ExtractBuildTask,
    'https://software-static.download.prss.microsoft.com/dbazure/988969d5-f34g-4e03-ac9d-1f9786c66749/EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso',
    'EWDK_ni_release_svc_prod1_22621_220804-1759.iso',
    ewdk_directory)
os.environ['EWDK_DIR'] = ewdk_directory
util.ewdk_dir = ewdk_directory

llvm_version = 'LLVM-15.0.6'
llvm_directory = os.path.join(util.bcs_third_party_dir, 'llvm')
llvm_bin_directory = os.path.join(llvm_directory, 'bin')
llvm_src_directory = os.path.join(llvm_directory, f'{llvm_version}.src')
llvm_task = download_extract_task(ExtractBuildTask,
    f'https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/{llvm_version}-win64.exe',
    f'{llvm_version}-win64.exe',
    llvm_directory,
    force=not os.path.exists(llvm_directory))
llvm_bin_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/{llvm_version}.src.tar.xz',
    f'{llvm_version}.src.tar.xz',
    llvm_directory,
    force=not os.path.exists(llvm_src_directory))
os.environ['LLVM_DIR'] = llvm_directory
os.environ['LLVM_BIN_DIR'] = llvm_bin_directory
os.environ['LLVM_SRC_DIR'] = llvm_src_directory

msys2_version = 'msys2-base-x86_64-20230127'
msys2_untar_directory = os.path.join(util.bcs_third_party_dir, f'msys2/{msys2_version}')
msys2_directory = os.path.join(msys2_untar_directory, 'msys64')
msys2_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://github.com/msys2/msys2-installer/releases/download/2023-01-27/{msys2_version}.tar.xz',
    f'{msys2_version}.tar.xz',
    msys2_untar_directory)
os.environ['MSYS2_DIR'] = msys2_directory
util.msys2_dir = msys2_directory

busybox_task = DownloadBuildTask(
    'https://frippery.org/files/busybox/busybox64.exe', 
    os.path.join(util.bcs_third_party_dir, 'busybox/busybox64.exe'))

winpix3_task = download_extract_task(ExtractBuildTask,
    'https://globalcdn.nuget.org/packages/winpixeventruntime.1.0.220810001.nupkg',
    'winpixeventruntime.1.0.220810001.nupkg',
    os.path.join(util.bcs_third_party_dir, 'winpixeventruntime/1.0.220810001'))

cmake_version = '3.25.2'
cmake_extract_directory = os.path.join(util.bcs_third_party_dir, 'cmake')
cmake_directory = os.path.join(cmake_extract_directory, f'cmake-{cmake_version}-windows-x86_64/bin')
cmake_task = download_extract_task(ExtractBuildTask,
    f'https://github.com/Kitware/CMake/releases/download/v{cmake_version}/cmake-{cmake_version}-windows-x86_64.zip',
    f'cmake-{cmake_version}-windows-x86_64.zip',
    cmake_extract_directory)
os.environ['CMAKE_DIR'] = cmake_directory
util.cmake_dir = cmake_directory
util.cmake_path = os.path.join(cmake_directory, "cmake.exe")

cmake_task = CMakeBuildTask([_7z_task])

musl_untar_directory = os.path.join(util.bcs_third_party_dir, f'musl')
musl_i686_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://musl.cc/i686-linux-musl-native.tgz',
    f'i686-linux-musl-native.tgz',
    musl_untar_directory,
    force=not os.path.exists(os.path.join(musl_untar_directory, 'i686-linux-musl-native')))
musl_x86_64_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://musl.cc/x86_64-linux-musl-native.tgz',
    f'x86_64-linux-musl-native.tgz',
    musl_untar_directory,
    force=not os.path.exists(os.path.join(musl_untar_directory, 'x86_64-linux-musl-native')))
musl_aarch64_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://musl.cc/aarch64-linux-musl-native.tgz',
    f'aarch64-linux-musl-native.tgz',
    musl_untar_directory,
    force=not os.path.exists(os.path.join(musl_untar_directory, 'aarch64-linux-musl-native')))
musl_arm_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://musl.cc/arm-linux-musleabi-native.tgz',
    f'arm-linux-musleabi-native.tgz',
    musl_untar_directory,
    force=not os.path.exists(os.path.join(musl_untar_directory, 'arm-linux-musleabi-native')))

wasi_untar_directory = os.path.join(util.bcs_third_party_dir, f'wasi/wasi-sdk-17')
wasi_directory = os.path.join(wasi_untar_directory, 'wasi-sysroot')
wasi_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-17/wasi-sysroot-17.0.tar.gz',
    f'wasi-sysroot-17.0.tar.gz',
    wasi_untar_directory,
    force=not os.path.exists(wasi_directory))
wasi_exceptions_untar_directory = os.path.join(util.bcs_third_party_dir, f'wasi/wasi-sdk-17-exceptions')
wasi_exceptions_directory = os.path.join(wasi_exceptions_untar_directory, 'wasi-sysroot')
wasi_exceptions_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
    f'https://github.com/ChimpsAtSea/wasi-sdk/releases/download/wasi-sdk-17-exceptions/wasi-sysroot-17.0.tar.gz',
    f'wasi-sysroot-17.0.tar.gz',
    wasi_exceptions_untar_directory,
    force=not os.path.exists(wasi_exceptions_directory))

directxshadercompiler_directory = os.path.join(util.bcs_third_party_dir, f'directxshadercompiler/directxshadercompiler')
directxshadercompiler_task = download_extract_task(ExtractBuildTask,
    f'https://github.com/ChimpsAtSea/DirectXShaderCompiler/releases/download/1.0.2139/dxc-artifacts.zip',
    f'dxc-artifacts-1.0.2139.zip',
    directxshadercompiler_directory)

msys2_init_task = MSYS2BuildTask([msys2_download_extract_task])
ninja_build_task = NinjaBuildTask()
gn_build_task = GNBuildTask([ninja_build_task])
yasm_build_task = YasmBuildTask([cmake_task, ninja_build_task])
ffmpeg_build_tasks = [
    FFMpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'shared', [yasm_build_task, msys2_init_task]),
    FFMpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'static', [yasm_build_task, msys2_init_task]),
    FFMpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'shared', [yasm_build_task, msys2_init_task]),
    FFMpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'static', [yasm_build_task, msys2_init_task]),
    FFMpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'shared', [yasm_build_task, msys2_init_task]),
    FFMpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'static', [yasm_build_task, msys2_init_task]) ]

# Automatically Build by GN Loopback see action_build_assimp.py
#assimp_build_tasks = [
#    AssimpBuildTask('arm64', True, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('arm64', False, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x64', True, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x64', False, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x86', True, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x86', False, [cmake_task, ninja_build_task]) ]

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
