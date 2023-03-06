
import os
import subprocess
import build_task_manager
import util

class GNBuildTask(build_task_manager.VisualCPPBuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__(f'GNBuildTask', "x64", _parent_tasks)

    def build(self):
        source_directory = os.path.join(util.bcs_third_party_dir, f'gn/gn')
        python_script = os.path.join(source_directory, 'build/gen.py')
        build_directory = os.path.join(util.bcs_third_party_dir, f'gn/gn_build')

        util.env_gn_dir = build_directory
        util.gn_path = os.path.join(util.env_gn_dir, "gn")

        if not util.command_line['rebuild-gn'] and os.path.exists(os.path.join(build_directory, 'gn.exe')):
            return # Don't rebuild

        paths = [
            os.path.join(util.bcs_third_party_dir, 'msys2-base-x86_64-20230127/msys64/usr/bin'),
            os.path.join(util.bcs_third_party_dir, 'yasm_build/Release'),
            os.path.join('C:/Program Files/Git/bin'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        process = subprocess.Popen([util.python_path, python_script, "--out-path", build_directory, "--use-lto"], env=self.environment, cwd=build_directory)
        process.wait()

        process = subprocess.Popen([util.ninja_path, "-C", build_directory, "gn.exe"], env=self.environment)
        process.wait()
