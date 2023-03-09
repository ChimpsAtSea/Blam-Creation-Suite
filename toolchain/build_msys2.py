import os
import subprocess
import build_task_manager
import build_task_manager
from build_extract import ExtractTarfileBuildTask
from build_download import download_extract_task
import util

class MSYS2BuildTask(build_task_manager.BuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__('MSYS2BuildTask', _parent_tasks)

    def build(self):
        if os.path.exists(os.path.join(util.bcs_msys2_dir, 'usr/bin/cmp.exe')):
            return # Don't init
        
        msys2_version = 'msys2-base-x86_64-20230127'
        msys2_untar_directory = os.path.join(util.bcs_third_party_dir, f'msys2/{msys2_version}')
        msys2_directory = os.path.join(msys2_untar_directory, 'msys64')
        msys2_download_extract_task = download_extract_task(ExtractTarfileBuildTask,
            f'https://github.com/msys2/msys2-installer/releases/download/2023-01-27/{msys2_version}.tar.xz',
            f'{msys2_version}.tar.xz',
            msys2_untar_directory)
        util.bcs_msys2_dir = msys2_directory

        msys2_download_extract_task.build()

        bash = os.path.join(util.bcs_msys2_dir, 'usr/bin/bash')
        shell_script = os.path.join(util.bcs_root_dir, 'toolchain\msys2_firstrun.sh')
        process = subprocess.Popen([bash, '-l', shell_script])
        process.wait()
