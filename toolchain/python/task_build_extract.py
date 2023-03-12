import os
import subprocess
from task_manager import BuildTask
import library_util as util

class ExtractBuildTask(BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = [], force = False):
        super().__init__('ExtractBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output
        self.force = force

    def build(self):
        super().build()
        
        if not self.force and os.path.exists(self.output):
            return # Don't extract
        
        destination_directory = os.path.dirname(self.filepath)
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)
        
        _7z = util.get_7z()
        command = [_7z, 'x', '-y', self.filepath, f'-o{self.output}']
        try:
            process = subprocess.Popen(command)
            process.wait()
        except Exception as e:
            print("ExtractBuildTask failed", command)
            raise e

class ExtractMSIBuildTask(BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = [], force = False):
        super().__init__('ExtractMSIBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output
        self.force = force

    def build(self):
        super().build()
        
        if not self.force and os.path.exists(self.output):
            return # Don't extract
        
        destination_directory = self.output
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        destination_directory = destination_directory.replace('/', '\\')
        
        process = subprocess.Popen(['msiexec', '/a', self.filepath, '/qn', f'TARGETDIR={destination_directory}'])
        process.wait()

class ExtractTarfileBuildTask(BuildTask):
    def __init__(self, filepath : str, output : str, _parent_tasks = [], force = False):
        super().__init__('ExtractTarfileBuildTask', _parent_tasks)
        self.filepath = filepath
        self.output = output
        self.force = force

    def build(self):
        super().build()
        
        if not self.force and os.path.exists(self.output):
            return # Don't extract
        
        destination_directory = self.output
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        destination_directory = destination_directory.replace('/', '\\')
        
        _7z = util.get_7z()
        command1 = [_7z, 'x', '-y', self.filepath, '-aoa', '-so']
        command2 = [_7z, 'x', '-y', '-aos', '-si', '-ttar', f'-o{self.output}']

        process1 = subprocess.Popen(command1, stdout=subprocess.PIPE)
        process2 = subprocess.Popen(command2, stdin=process1.stdout)

        process1.wait()
        process2.wait()

        process1.stdout.close()
