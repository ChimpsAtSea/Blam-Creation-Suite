
import os
import subprocess
import build_task_manager
import util

class DownloadBuildTask(build_task_manager.BuildTask):
    def __init__(self, url : str, filepath : str, _parent_tasks = []):
        super().__init__(f'DownloadBuildTask', _parent_tasks)
        self.url = url
        self.filepath = filepath

    def build(self):
        if os.path.exists(self.filepath):
            return # Don't download
        
        destination_directory = os.path.dirname(self.filepath)
        
        if not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        process = subprocess.Popen(['curl', '-L', self.url, '-o', self.filepath])
        process.wait()
