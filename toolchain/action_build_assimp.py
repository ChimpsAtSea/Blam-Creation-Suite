import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import project_setup
import sln
import util
import build_task_manager
from build_ninja import NinjaBuildTask
from build_assimp import AssimpBuildTask
from build_cmake import CMakeBuildTask
from build_download import download_extract_task

util.async_start()

cmake_task = CMakeBuildTask()
ninja_build_task = NinjaBuildTask()
assimp_build_tasks = [
    AssimpBuildTask('arm64', True, [cmake_task, ninja_build_task]),
    AssimpBuildTask('arm64', False, [cmake_task, ninja_build_task]),
    AssimpBuildTask('x64', True, [cmake_task, ninja_build_task]),
    AssimpBuildTask('x64', False, [cmake_task, ninja_build_task]),
    AssimpBuildTask('x86', True, [cmake_task, ninja_build_task]),
    AssimpBuildTask('x86', False, [cmake_task, ninja_build_task]) ]

while build_task_manager.BuildTaskManager.process_tasks():
    pass

util.async_end()
