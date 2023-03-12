
import os
import subprocess
from task_manager import VisualCPPBuildTask
import library_util as util

class NinjaBuildTask(VisualCPPBuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__('NinjaBuildTask', "x64", _parent_tasks)

    def build(self):
        super().build()
        
        source_directory = os.path.join(util.bcs_third_party_dir, f'ninja/ninja')
        build_directory = os.path.join(util.bcs_third_party_dir, f'ninja/ninja_build')

        util.bcs_ninja_dir = build_directory
        ninja = util.get_ninja()

        if os.path.exists(ninja):
            return # Don't rebuild

        paths = [
            #os.path.join(util.bcs_third_party_dir, 'ninja'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        self.environment['CL'] = ' '.join([self.environment['CL']] + ['/wd4005', '/wd4244', '/wd4267', '/wd4312'])

        self.environment['PYTHONWARNINGS'] = 'ignore::DeprecationWarning'

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        python = util.get_python()
        process = subprocess.Popen([python, os.path.join(source_directory, 'configure.py'), '--bootstrap'], env=self.environment, cwd=build_directory)
        process.wait()
