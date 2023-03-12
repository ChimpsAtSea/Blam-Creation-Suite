import os
from task_manager import BuildTask
from task_build_extract import ExtractBuildTask
from task_build_download import download_extract_task
import library_util as util

class WinPix3BuildTask(BuildTask):
    def __init__(self, target_cpu : str, _parent_tasks = []):
        super().__init__('WinPix3BuildTask', _parent_tasks)
        self.version = 'winpixeventruntime.1.0.220810001'
        self.extract_directory = os.path.join(util.bcs_third_party_dir, f'winpix3/{self.version}')
        self.directory = os.path.join(self.extract_directory, 'bin', target_cpu.upper())
        self.output_library = os.path.join(self.directory, 'WinPixEventRuntime.lib')
        self.output_binary = os.path.join(self.directory, 'WinPixEventRuntime.dll')

    def build(self):
        super().build()
        
        util.bcs_winpix3_dir = self.directory
        
        if os.path.exists(self.output_binary):
            return # Don't init

        winpix3_download_extract_task = download_extract_task(ExtractBuildTask,
            f'https://globalcdn.nuget.org/packages/{self.version}.nupkg',
            f'{self.version}.nupkg',
            self.extract_directory)

        winpix3_download_extract_task.build()
