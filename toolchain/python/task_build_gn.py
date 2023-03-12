
import os
import subprocess
from task_manager import VisualCPPBuildTask
import library_util as util

class GNBuildTask(VisualCPPBuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__('GNBuildTask', "x64", _parent_tasks)

    def build(self):
        super().build()
        
        source_directory = os.path.join(util.bcs_third_party_dir, f'gn/gn')
        python_script = os.path.join(source_directory, 'build/gen.py')
        build_directory = os.path.join(util.bcs_third_party_dir, f'gn/gn_build')

        util.bcs_gn_dir = build_directory

        if not util.command_line['build-gn'] and os.path.exists(os.path.join(build_directory, 'gn.exe')):
            return # Don't rebuild

        paths = [
            os.path.join('C:/Program Files/Git/bin'), #TODO Remove this system path!!!
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        python = util.get_python()
        process = subprocess.Popen([python, python_script, "--out-path", build_directory, "--use-lto"], env=self.environment, cwd=build_directory)
        process.wait()

        ninja = util.get_ninja()
        process = subprocess.Popen([ninja, "-C", build_directory, "gn.exe"], env=self.environment)
        process.wait()
