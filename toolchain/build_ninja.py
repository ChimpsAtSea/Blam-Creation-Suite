
import os
import subprocess
import build_task_manager
import util

class NinjaBuildTask(build_task_manager.VisualCPPBuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__(f'NinjaBuildTask', "x64", _parent_tasks)

    def build(self):
        source_directory = os.path.join(util.bcs_third_party_dir, f'ninja/ninja')
        build_directory = os.path.join(util.bcs_third_party_dir, f'ninja/ninja_build')

        if os.path.exists(os.path.join(build_directory, 'ninja.exe')):
            return # Don't rebuild

        paths = [
            #os.path.join(util.bcs_third_party_dir, 'ninja'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        self.environment['CL'] = ' '.join([self.environment['CL']] + ['/wd4005', '/wd4244', '/wd4267', '/wd4312'])

        self.environment['PYTHONWARNINGS'] = 'ignore::DeprecationWarning'

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        process = subprocess.Popen([util.python_path, os.path.join(source_directory, 'configure.py'), '--bootstrap'], env=self.environment, cwd=build_directory)
        process.wait()
