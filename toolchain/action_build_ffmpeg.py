import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import util
import build_task_manager
from build_ninja import NinjaBuildTask
from build_cmake import CMakeBuildTask
from build_extract import ExtractTarfileBuildTask
from build_msys2 import MSYS2BuildTask
from build_yasm import YasmBuildTask
from build_ffmpeg import FFmpegBuildTask
from build_copy import CopyBuildTask
from build_download import download_extract_task

util.async_start()

cmake_task = CMakeBuildTask()
ninja_build_task = NinjaBuildTask()

msys2_init_task = MSYS2BuildTask()
yasm_build_task = YasmBuildTask([cmake_task, ninja_build_task])

target_cpu_to_arch = {
    'arm64': 'aarch64',
    'x64': 'x86_64',
    'x86': 'x86_32',
}
arch = target_cpu_to_arch[util.target_cpu]

ffmpeg_build_task = FFmpegBuildTask('win32', arch, 'msvc', util.target_cpu, util.target_link_config, [yasm_build_task, msys2_init_task])
output = util.command_line['output']

build_task_manager.BuildTaskManager.run_until_complete()

for output_library in ffmpeg_build_task.output_libraries:
    ffmpeg_copy_tasks = [ CopyBuildTask(output_library, os.path.join(output, f'lib/{os.path.basename(output_library)}'), [ffmpeg_build_task]) ]
if util.target_link_config == 'shared':
    for output_binary in ffmpeg_build_task.output_binaries:
        ffmpeg_copy_tasks += [ CopyBuildTask(output_binary, os.path.join(output, f'bin/{os.path.basename(output_binary)}'), [ffmpeg_build_task]) ]

build_task_manager.BuildTaskManager.run_until_complete()

util.async_end()
