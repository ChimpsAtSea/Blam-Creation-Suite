import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import library_util as util
from task_manager import BuildTaskManager
from task_build_stamp import StampBuildTask

util.async_start()

target = util.command_line['target']

stamp_task = StampBuildTask(target)

BuildTaskManager.run_until_complete()

util.async_end()
