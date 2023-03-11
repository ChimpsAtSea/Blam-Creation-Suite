
import os
import build_task_manager
import pathlib

class StampBuildTask(build_task_manager.BuildTask):
    def __init__(self, target : str, _parent_tasks = []):
        super().__init__('CopyBuildTask', _parent_tasks)
        self.target = target

    def build(self):
        if not os.path.exists(self.target):
            with open(self.target, "w") as target_file:
                target_file.write("monkey")
        
        pathlib.Path(self.target).touch()
