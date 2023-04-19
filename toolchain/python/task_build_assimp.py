import os
import sys
import subprocess
import shlex
from task_manager import VisualCPPBuildTask
import library_util as util
import library_project_setup as project_setup

class AssimpBuildTask(VisualCPPBuildTask):
    def __init__(self, msvc_target, target_config, use_shared_libs, _parent_tasks = []):
        super().__init__('AssimpBuildTask', msvc_target, _parent_tasks)
        self.use_shared_libs : bool = use_shared_libs
        self.link_configuration = 'shared' if self.use_shared_libs else 'static'
        self.target_config = target_config
        
        self.configuration = project_setup.vs_configuration_to_cmake_configuration(target_config)

        self.build_folder_name = f'assimp_build_{self.target_config}_{self.msvc_target}_{self.link_configuration}'
        self.source_directory = os.path.join(util.bcs_third_party_dir, 'assimp/assimp')
        self.build_directory = os.path.join(util.bcs_third_party_dir, 'assimp', self.build_folder_name)
        self.output_library = os.path.join(self.build_directory, 'lib/assimp.lib')
        self.output_binary = os.path.join(self.build_directory, 'bin/assimp.dll') if self.use_shared_libs else None

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
            '-DCMAKE_CXX_COMPILER=cl',
            f'-DCMAKE_BUILD_TYPE:STRING={self.configuration}',
            '-DASSIMP_INSTALL:BOOL=0',
            '-DASSIMP_DOUBLE_PRECISION:BOOL=1',
            '-DASSIMP_LIBRARY_SUFFIX:STRING=',
            '-DASSIMP_LIB_INSTALL_DIR:STRING=lib',
            '-DASSIMP_BUILD_TESTS:BOOL=0',
            '-DASSIMP_INSTALL_PDB:BOOL=0',
            '-DASSIMP_WARNINGS_AS_ERRORS:BOOL=0',
            '-DCMAKE_DEBUG_POSTFIX:STRING=',
            '-DLIBRARY_SUFFIX:STRING=',
            f'-DBUILD_SHARED_LIBS:BOOL={ 1 if self.use_shared_libs else 0 }',
            f'-DUSE_STATIC_CRT:BOOL={ 0 if self.use_shared_libs else 1 }' ]

        print(f'CMake generating Assimp build files {self.build_folder_name}')
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
            # Fix a warning with CMake shoving /MT and /MD flags into the same command line
            for index, line in enumerate(build_ninja):
                if line.startswith('  FLAGS ='):
                    flags = line[len('  FLAGS ='):]
                    if flags:
                        flags_list = shlex.split(flags)
                        new_flags_list = []
                        for flag in flags_list:
                            if not flag is '/MD':
                                new_flags_list.append(flag)
                        new_flags = shlex.join(new_flags_list)
                        build_ninja[index] = f'  FLAGS = {new_flags}\n'
        
        with open(build_ninja_filepath, 'w') as build_ninja_file:
            build_ninja_file.writelines(build_ninja)
        
        ninja_args = [ninja, '-C', self.build_directory]
        process = subprocess.Popen(ninja_args, env=self.environment)
        process.wait()
        if process.returncode:
            print(ninja_args)
            raise Exception("Ninja Failed")
