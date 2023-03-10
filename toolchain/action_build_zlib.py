import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import util
import build_task_manager
from build_ninja import NinjaBuildTask
from build_zlib import ZlibBuildTask
from build_cmake import CMakeBuildTask
from build_copy import CopyBuildTask

util.async_start()

cmake_task = CMakeBuildTask()
ninja_build_task = NinjaBuildTask()

target_cpu = util.command_line['target_cpu']
target_link_config = util.command_line['target_link_config']
output = util.command_line['output']

zlib_build_shared = target_link_config == 'shared'
zlib_build_task = ZlibBuildTask(target_cpu, zlib_build_shared, [cmake_task, ninja_build_task])
if zlib_build_shared:
    zlib_copy_tasks = [
        CopyBuildTask(zlib_build_task.output_library, os.path.join(output, 'lib/zlib.lib'), [zlib_build_task]),
        CopyBuildTask(zlib_build_task.output_binary, os.path.join(output, 'bin/zlib1.dll'), [zlib_build_task]) ]
else:
    zlib_copy_tasks = [ CopyBuildTask(zlib_build_task.output_library, os.path.join(output, 'lib/zlibstatic.lib'), [zlib_build_task]) ]

build_task_manager.BuildTaskManager.run_until_complete()

util.async_end()
