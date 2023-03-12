import os
import sys
import subprocess
from task_manager import VisualCPPBuildTask
import library_util as util

class ZlibBuildTask(VisualCPPBuildTask):
    def __init__(self, msvc_target, use_shared_libs, _parent_tasks = []):
        super().__init__('ZlibBuildTask', msvc_target, _parent_tasks)
        self.use_shared_libs : bool = use_shared_libs
        self.link_configuration = 'shared' if self.use_shared_libs else 'static'
        self.build_folder_name = f'zlib_build_{self.msvc_target}_{self.link_configuration}'
        self.source_directory = os.path.join(util.bcs_third_party_dir, 'zlib/zlib')
        self.build_directory = os.path.join(util.bcs_third_party_dir, 'zlib', self.build_folder_name)
        self.output_library = os.path.join(self.build_directory, 'zlib.lib' if self.use_shared_libs else 'zlibstatic.lib')
        self.output_binary = os.path.join(self.build_directory, 'zlib1.dll') if self.use_shared_libs else None

    def build(self):
        super().build()
        
        is_library_built = os.path.exists(self.output_library)
        is_binary_built = False if self.output_binary == None else os.path.exists(self.output_binary)
        if is_library_built and is_binary_built:
            return # Don't rebuild

        paths = [
            #os.path.join(util.bcs_third_party_dir, 'ninja'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        #self.environment['CL'] = ' '.join([self.environment['CL']] + ['/wd4005', '/wd4244', '/wd4267', '/wd4312'])

        if not os.path.exists(self.build_directory):
            os.makedirs(self.build_directory)

        ninja = util.get_ninja()
        cmake = util.get_cmake()
        cmake_args = [
            cmake,
            '-S', self.source_directory,
            '-B', self.build_directory,
            '-G', 'Ninja',
            '--log-level=NOTICE',
            '-Wno-dev',
            '-Wno-deprecated',
            f'-DCMAKE_MAKE_PROGRAM={ninja}',
            '-DCMAKE_C_COMPILER=cl',
            '-DCMAKE_BUILD_TYPE:STRING=Release',
            '-DCMAKE_DEBUG_POSTFIX:STRING=' ]

        if self.use_shared_libs:
            cmake_args += [
                '-DBUILD_SHARED_LIBS:BOOL=1' ]
        else:
            cmake_args += [
                '-DBUILD_SHARED_LIBS:BOOL=0' ]

        print(f'CMake generating Zlib build files {self.build_folder_name}')
        sys.stdout.flush()
        process = subprocess.Popen(cmake_args, env=self.environment, cwd=self.build_directory)
        process.wait()
        if process.returncode:
            print(cmake_args)
            raise Exception("CMake Failed")
        
        build_ninja_filepath = os.path.join(self.build_directory, 'build.ninja')
        build_ninja = []
        with open(build_ninja_filepath, 'r') as build_ninja_file:
            build_ninja = build_ninja_file.readlines()
        
        if not self.use_shared_libs:
            # Fix unable to configure usage of the static c runtime
            for index, line in enumerate(build_ninja):
                if line.startswith('  FLAGS ='):
                    build_ninja[index] = line.replace('/MD', '/MT')
        
        with open(build_ninja_filepath, 'w') as build_ninja_file:
            build_ninja_file.writelines(build_ninja)
        
        if self.use_shared_libs:
            ninja_args = [ninja, '-C', self.build_directory, 'zlib1.dll']
        else:
            ninja_args = [ninja, '-C', self.build_directory, 'zlibstatic.lib']
        process = subprocess.Popen(ninja_args, env=self.environment)
        process.wait()
        if process.returncode:
            print(ninja_args)
            raise Exception("Ninja Failed")
