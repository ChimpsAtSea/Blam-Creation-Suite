import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import library_util as util
from task_manager import BuildTaskManager
from task_build_ninja import NinjaBuildTask
from task_build_zlib import ZlibBuildTask
from task_build_cmake import CMakeBuildTask
from task_build_copy import CopyBuildTask
from task_build_move import MoveBuildTask

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

zconf_included = os.path.join(zlib_build_task.source_directory, 'zconf.h.included')
zconf = os.path.join(zlib_build_task.source_directory, 'zconf.h')
if os.path.exists(zconf_included):
    zlib_git_fixup_task = MoveBuildTask(zconf_included, zconf, zlib_copy_tasks)

BuildTaskManager.run_until_complete()

util.async_end()
