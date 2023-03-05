
import os
import subprocess
import build_task_manager
import util

class ExtractBuildTask(build_task_manager.BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = []):
        super().__init__(f'ExtractBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output

    def build(self):
        _7z_path = os.path.join(os.environ['_7Z_DIR'], "7z")

        if os.path.exists(self.output):
            return # Don't extract
        
        destination_directory = os.path.dirname(self.filepath)
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)
        
        print(_7z_path)
        process = subprocess.Popen([_7z_path, 'x', '-y', self.filepath, f'-o{self.output}'])
        process.wait()

class ExtractMSIBuildTask(build_task_manager.BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = []):
        super().__init__(f'ExtractMSIBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output

    def build(self):
        if os.path.exists(self.output):
            return # Don't extract
        
        destination_directory = self.output
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        destination_directory = destination_directory.replace('/', '\\')
        
        print(['msiexec', '/a', self.filepath, '/qn', f'TARGETDIR={destination_directory}'])
        process = subprocess.Popen(['msiexec', '/a', self.filepath, '/qn', f'TARGETDIR={destination_directory}'])
        process.wait()
