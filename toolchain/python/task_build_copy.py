
import os
from task_manager import BuildTask
import shutil

class CopyBuildTask(BuildTask):
    def __init__(self, source : str, destination : str, _parent_tasks = []):
        super().__init__('CopyBuildTask', _parent_tasks)
        self.source = source
        self.destination = destination

    def build(self):
        super().build()
        
        destination_directory = os.path.dirname(self.destination)
        if os.path.isfile(self.source) and not os.path.exists(destination_directory):
            os.makedirs(destination_directory)

        try:
            if not os.path.exists(self.destination) or os.path.getmtime(self.source) > os.path.getmtime(self.destination):
                shutil.copy2(self.source, self.destination)
        except Exception as e:
            print(f'Failed to copy from {self.source} to {self.destination}')
            raise e
