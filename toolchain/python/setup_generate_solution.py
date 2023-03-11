import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import library_project_setup as project_setup
import library_sln as sln
import library_util as util
from task_manager import BuildTaskManager
from task_build_download import DownloadBuildTask
from task_build_extract import ExtractBuildTask
from task_build_extract import ExtractMSIBuildTask
from task_build_extract import ExtractTarfileBuildTask
from task_build_ninja import NinjaBuildTask
from task_build_gn import GNBuildTask
from task_build_yasm import YasmBuildTask
from task_build_zlib import ZlibBuildTask
from task_build_ffmpeg import FFmpegBuildTask
from task_build_msys2 import MSYS2BuildTask
from task_build_winpix3 import WinPix3BuildTask
from task_build_assimp import AssimpBuildTask
from task_build_cmake import CMakeBuildTask
from task_build_download import download_extract_task

util.async_start()

bcs_toolchain_python_dir = os.path.realpath(os.path.dirname(__file__))
bcs_toolchain_dir = os.path.dirname(bcs_toolchain_python_dir)
bcs_root_dir = os.path.dirname(bcs_toolchain_dir)
bcs_third_party_dir = os.path.join(bcs_root_dir, "thirdparty")
if not os.path.exists(bcs_third_party_dir):
    raise Exception("Third party directory not found ", bcs_third_party_dir)

util.bcs_root_dir = bcs_root_dir
util.bcs_third_party_dir = bcs_third_party_dir
util.bcs_toolchain_dir = bcs_toolchain_dir
util.bcs_python_dir = os.path.dirname(sys.executable) #NOTE Is this safe?

_7z_directory = os.path.join(util.bcs_third_party_dir, '7-Zip/7z2201-x64/Files/7-Zip')
_7z_task = download_extract_task(ExtractMSIBuildTask,
    'https://www.7-zip.org/a/7z2201-x64.msi',
    '7z2201-x64.msi',
    _7z_directory)
util.bcs_7z_dir = _7z_directory

bcs_ewdk_directory = os.path.join(util.bcs_third_party_dir, 'EWDK/EWDK_ni_release_svc_prod1_22621_220804-1759')
ewdk_task = download_extract_task(ExtractBuildTask,
    'https://software-static.download.prss.microsoft.com/dbazure/988969d5-f34g-4e03-ac9d-1f9786c66749/EWDK_ni_release_svc_prod1_22621_220804-1759.iso',
    'EWDK_ni_release_svc_prod1_22621_220804-1759.iso',
    bcs_ewdk_directory)
util.bcs_ewdk_dir = bcs_ewdk_directory

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
util.bcs_llvm_dir = llvm_directory
util.bcs_llvm_bin_dir = llvm_bin_directory
util.bcs_llvm_src_dir = llvm_src_directory

busybox_task = DownloadBuildTask(
    'https://frippery.org/files/busybox/busybox64.exe', 
    os.path.join(util.bcs_third_party_dir, 'busybox/busybox64.exe'))

#winpix3_task = WinPix3BuildTask()

cmake_version = '3.25.2'
cmake_extract_directory = os.path.join(util.bcs_third_party_dir, 'cmake')
cmake_directory = os.path.join(cmake_extract_directory, f'cmake-{cmake_version}-windows-x86_64/bin')
cmake_task = download_extract_task(ExtractBuildTask,
    f'https://github.com/Kitware/CMake/releases/download/v{cmake_version}/cmake-{cmake_version}-windows-x86_64.zip',
    f'cmake-{cmake_version}-windows-x86_64.zip',
    cmake_extract_directory)
util.bcs_cmake_dir = cmake_directory

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

ninja_build_task = NinjaBuildTask([ewdk_task])
gn_build_task = GNBuildTask([ninja_build_task])
msys2_init_task = MSYS2BuildTask()
yasm_build_task = YasmBuildTask([cmake_task, ninja_build_task])

#zlib_build_task = ZlibBuildTask([cmake_task, ninja_build_task])
#zlib_build_tasks = [
#    ZlibBuildTask('arm64', True, [cmake_task, ninja_build_task]),
#    ZlibBuildTask('arm64', False, [cmake_task, ninja_build_task]),
#    ZlibBuildTask('x64', True, [cmake_task, ninja_build_task]),
#    ZlibBuildTask('x64', False, [cmake_task, ninja_build_task]),
#    ZlibBuildTask('x86', True, [cmake_task, ninja_build_task]),
#    ZlibBuildTask('x86', False, [cmake_task, ninja_build_task]) ]

#TODO build all command
# Automatically Build by GN Loopback see action_build_ffmpeg.py
#ffmpeg_build_tasks = [
#    FFmpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'shared', [yasm_build_task, msys2_init_task]),
#    FFmpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'static', [yasm_build_task, msys2_init_task]),
#    FFmpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'shared', [yasm_build_task, msys2_init_task]),
#    FFmpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'static', [yasm_build_task, msys2_init_task]),
#    FFmpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'shared', [yasm_build_task, msys2_init_task]),
#    FFmpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'static', [yasm_build_task, msys2_init_task]) ]

#TODO build all command
# Automatically Build by GN Loopback see action_build_assimp.py
#assimp_build_tasks = [
#    AssimpBuildTask('arm64', True, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('arm64', False, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x64', True, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x64', False, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x86', True, [cmake_task, ninja_build_task]),
#    AssimpBuildTask('x86', False, [cmake_task, ninja_build_task]) ]

BuildTaskManager.run_until_complete()

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
