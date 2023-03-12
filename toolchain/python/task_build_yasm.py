
import os
import subprocess
from task_manager import VisualCPPBuildTask
import library_util as util

class YasmBuildTask(VisualCPPBuildTask):
    def __init__(self, _parent_tasks = []):
        super().__init__('YasmBuildTask', "x64", _parent_tasks)

    def build(self):
        super().build()
        
        source_directory = os.path.join(util.bcs_third_party_dir, f'yasm/yasm')
        build_directory = os.path.join(util.bcs_third_party_dir, f'yasm/yasm_build')

        util.bcs_yasm_dir = build_directory

        if os.path.exists(os.path.join(build_directory, 'yasm.exe')):
            return # Don't rebuild

        paths = [
            #os.path.join(util.bcs_third_party_dir, 'ninja'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        self.environment['CL'] = ' '.join([self.environment['CL']] + ['/wd4005', '/wd4244', '/wd4267', '/wd4312'])

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        ninja = util.get_ninja()
        cmake = util.get_cmake()
        cmake_args = [
            cmake,
            '-S', source_directory,
            '-B', build_directory,
            '-G', 'Ninja',
            '--log-level=NOTICE',
            '-Wno-dev',
            '-Wno-deprecated',
            f'-DCMAKE_MAKE_PROGRAM={ninja}',
            '-DCMAKE_C_COMPILER=cl',
            '-DCMAKE_CXX_COMPILER=cl',
            '-DCMAKE_BUILD_TYPE:STRING=Release',
            '-DBUILD_SHARED_LIBS:BOOL=0',
            '-DYASM_BUILD_TESTS:BOOL=0'
        ]

        print("CMake generating YASM build files")

        process = subprocess.Popen(cmake_args, env=self.environment, cwd=build_directory)
        process.wait()

        process = subprocess.Popen([ninja, "-C", build_directory, "yasm.exe"], env=self.environment)
        process.wait()
