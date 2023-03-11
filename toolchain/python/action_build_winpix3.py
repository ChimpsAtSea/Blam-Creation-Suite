import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import library_util as util
from task_manager import BuildTaskManager
from task_build_winpix3 import WinPix3BuildTask
from task_build_copy import CopyBuildTask

util.async_start()

target_cpu = util.command_line['target_cpu']
output = util.command_line['output']

winpix3_task = WinPix3BuildTask(target_cpu)
winpix3_copy_tasks = [
    CopyBuildTask(winpix3_task.output_library, os.path.join(output, 'lib/WinPixEventRuntime.lib'), [winpix3_task]),
    CopyBuildTask(winpix3_task.output_binary, os.path.join(output, 'bin/WinPixEventRuntime.dll'), [winpix3_task]) ]

BuildTaskManager.run_until_complete()

util.async_end()
