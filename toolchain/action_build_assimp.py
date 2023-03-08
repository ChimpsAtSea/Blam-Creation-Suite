import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import util
import build_task_manager
from build_ninja import NinjaBuildTask
from build_assimp import AssimpBuildTask
from build_cmake import CMakeBuildTask
from build_copy import CopyBuildTask
from build_download import download_extract_task

util.async_start()

cmake_task = CMakeBuildTask()
ninja_build_task = NinjaBuildTask()

target_cpu = util.command_line['target_cpu']
target_link_config = util.command_line['target_link_config']
output = util.command_line['output']

assimp_build_shared = target_link_config == 'shared'
assimp_build_task = AssimpBuildTask(target_cpu, assimp_build_shared, [cmake_task, ninja_build_task])
assimp_copy_tasks = [ CopyBuildTask(assimp_build_task.output_library, os.path.join(output, "lib/assimp.lib"), [assimp_build_task]) ]
if assimp_build_shared:
    assimp_copy_tasks += [ CopyBuildTask(assimp_build_task.output_binary, os.path.join(output, "bin/assimp.dll"), [assimp_build_task]) ]

while build_task_manager.BuildTaskManager.process_tasks():
    pass

util.async_end()
