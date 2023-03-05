
import os
import subprocess
import util

class BuildTask:
    name : str
    is_built : bool
    parent_tasks : list
    
    def __init__(self, name, _parent_tasks = []):
        self.name = name
        self.is_built = False
        self.parent_tasks : list[BuildTask] = [] + _parent_tasks
        BuildTaskManager.register_task(self)

    def can_build(self):
        for wait_for_task in self.parent_tasks:
            if not wait_for_task.is_built:
                return False
        return True

    def build(self):
        raise Exception('No build function')

class BuildTaskManager:
    tasks : list[BuildTask] = []

    def register_task(task : BuildTask):
        BuildTaskManager.tasks.append(task)
    
    def is_finished():
        for task in BuildTaskManager.tasks:
            if not task.is_built:
                return False
        return True

    def get_next_task():
        for task in BuildTaskManager.tasks:
            if not task.is_built and task.can_build():
                return task
        return None

    def log_tasks():
        for task in BuildTaskManager.tasks:
            if not task.is_built:
                task_pending_names = ' '
                for parent_task in task.parent_tasks:
                    task_pending_names += f'\'{parent_task.name}\' '
                print(f'\t{task.name} [{task_pending_names}]')

    def process_tasks():
        if BuildTaskManager.is_finished():
            return False
        
        next_task = BuildTaskManager.get_next_task()
        if next_task == None:
            print('Unable to execute next task')
            print('Pending Tasks:')
            BuildTaskManager.log_tasks()
            raise Exception('Unable to execute next task')
        next_task.build()
        next_task.is_built = True

        return True
