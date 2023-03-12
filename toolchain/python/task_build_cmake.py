
import os
from task_manager import BuildTask
from task_build_extract import ExtractBuildTask
from task_build_download import DownloadBuildTask
from task_build_download import download_extract_task
import library_util as util

class CMakeBuildTask(BuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__('CMakeBuildTask', _parent_tasks)

    def build(self):
        super().build()
        
        cmake_version = '3.25.2'
        cmake_extract_directory = os.path.join(util.bcs_third_party_dir, 'cmake')
        cmake_directory = os.path.join(cmake_extract_directory, f'cmake-{cmake_version}-windows-x86_64/bin')
        util.bcs_cmake_dir = cmake_directory

        url = f'https://github.com/Kitware/CMake/releases/download/v{cmake_version}/cmake-{cmake_version}-windows-x86_64.zip'
        cache_filename = f'cmake-{cmake_version}-windows-x86_64.zip'
        output_directory = cmake_extract_directory

        download_filepath = os.path.join(util.bcs_download_cache_dir, cache_filename)
        download_task = DownloadBuildTask(url, download_filepath)
        extract_task = ExtractBuildTask(download_filepath, output_directory, [download_task])

        download_task.build()
        extract_task.build()
