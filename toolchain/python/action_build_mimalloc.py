import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import library_util as util
from task_manager import BuildTaskManager
from task_build_ninja import NinjaBuildTask
from task_build_mimalloc import MimallocBuildTask
from task_build_cmake import CMakeBuildTask
from task_build_copy import CopyBuildTask

util.async_start()

cmake_task = CMakeBuildTask()
ninja_build_task = NinjaBuildTask()

target_cpu = util.command_line['target_cpu']
target_config = util.command_line['target_config']
target_link_config = util.command_line['target_link_config']
output = util.command_line['output']

mimalloc_build_shared = target_link_config == 'shared'
mimalloc_build_shared = True #TODO: Issue building static library
mimalloc_build_task = MimallocBuildTask(target_cpu, target_config, mimalloc_build_shared, [cmake_task, ninja_build_task])

mimalloc_copy_tasks = [ CopyBuildTask(mimalloc_build_task.output_library, os.path.join(output, f'lib/mimalloc{mimalloc_build_task.output_suffix}.lib'), [mimalloc_build_task]) ]
if mimalloc_build_shared:
    mimalloc_copy_tasks += [ CopyBuildTask(mimalloc_build_task.output_binary, os.path.join(output, f'bin/mimalloc{mimalloc_build_task.output_suffix}.dll'), [mimalloc_build_task]) ]

BuildTaskManager.run_until_complete()

util.async_end()
print(mimalloc_build_task.output_library)
print(mimalloc_build_task.output_binary)