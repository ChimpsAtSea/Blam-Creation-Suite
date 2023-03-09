import os
import subprocess
import build_task_manager
import util

class MSYS2BuildTask(build_task_manager.BuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__('MSYS2BuildTask', _parent_tasks)

    def build(self):
        if os.path.exists(os.path.join(util.bcs_msys2_dir, 'usr/bin/cmp.exe')):
            return # Don't init
        
        bash = os.path.join(util.bcs_msys2_dir, 'usr/bin/bash')
        shell_script = os.path.join(util.bcs_root_dir, 'toolchain\msys2_firstrun.sh')
        process = subprocess.Popen([bash, '-l', shell_script])
        process.wait()
