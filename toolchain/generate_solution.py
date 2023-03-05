import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import project_setup
import sln
import util
import build_task_manager
import build_ffmpeg
import build_gn
import build_yasm
import build_ninja

util.async_start()

ninja_build_task = build_ninja.NinjaBuildTask()
gn_build_task = build_gn.GNBuildTask([ninja_build_task])
yasm_build_task = build_yasm.YasmBuildTask([ninja_build_task])
ffmpeg_build_tasks = [
    build_ffmpeg.FFMpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'static', [yasm_build_task]),
    build_ffmpeg.FFMpegBuildTask('win32', 'aarch64', 'msvc', 'arm64', 'shared', [yasm_build_task]),
    build_ffmpeg.FFMpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'static', [yasm_build_task]),
    build_ffmpeg.FFMpegBuildTask('win32', 'x86_32', 'msvc', 'x86', 'shared', [yasm_build_task]),
    build_ffmpeg.FFMpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'static', [yasm_build_task]),
    build_ffmpeg.FFMpegBuildTask('win32', 'x86_64', 'msvc', 'x64', 'shared', [yasm_build_task]),
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
