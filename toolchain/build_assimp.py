
import os
import subprocess
import build_task_manager
import util

class AssimpBuildTask(build_task_manager.VisualCPPBuildTask):
    def __init__(self, msvc_target, use_shared_libs, _parent_tasks = []):
        super().__init__('AssimpBuildTask', msvc_target, _parent_tasks)
        self.use_shared_libs : bool = use_shared_libs

    def build(self):
        link_configuration = 'shared' if self.use_shared_libs else 'static'
        build_folder_name = f'assimp_build_{self.msvc_target}_{link_configuration}'

        source_directory = os.path.join(util.bcs_third_party_dir, 'assimp/assimp')
        build_directory = os.path.join(util.bcs_third_party_dir, 'assimp', build_folder_name)

        if os.path.exists(os.path.join(build_directory, 'lib/assimp.lib')):
            return # Don't rebuild

        paths = [
            #os.path.join(util.bcs_third_party_dir, 'ninja'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        #self.environment['CL'] = ' '.join([self.environment['CL']] + ['/wd4005', '/wd4244', '/wd4267', '/wd4312'])

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        cmake_args = [
            util.cmake_path,
            '-S', source_directory,
            '-B', build_directory,
            '-G', 'Ninja',
            '--log-level=NOTICE',
            '-Wno-dev',
            '-Wno-deprecated',
            f'-DCMAKE_MAKE_PROGRAM={util.ninja_path}',
            '-DCMAKE_C_COMPILER=cl',
            '-DCMAKE_CXX_COMPILER=cl',
            '-DCMAKE_BUILD_TYPE:STRING=Release',
            '-DASSIMP_INSTALL:BOOL=0',
            '-DASSIMP_DOUBLE_PRECISION:BOOL=1',
            '-DASSIMP_LIBRARY_SUFFIX:STRING=',
            '-DASSIMP_LIB_INSTALL_DIR:STRING=lib',
            '-DASSIMP_BUILD_TESTS:BOOL=0',
            '-DASSIMP_INSTALL_PDB:BOOL=0',
            '-DASSIMP_WARNINGS_AS_ERRORS:BOOL=0',
            '-DCMAKE_DEBUG_POSTFIX:STRING=',
            '-DLIBRARY_SUFFIX:STRING=' ]

        if self.use_shared_libs:
            cmake_args += [
                '-DBUILD_SHARED_LIBS:BOOL=1',
                '-DUSE_STATIC_CRT:BOOL=0' ]
        else:
            cmake_args += [
                '-DBUILD_SHARED_LIBS:BOOL=0',
                '-DUSE_STATIC_CRT:BOOL=1' ]

        print(f'CMake generating Assimp build files {build_folder_name}')

        process = subprocess.Popen(cmake_args, env=self.environment, cwd=build_directory)
        process.wait()

        build_ninja_filepath = os.path.join(build_directory, 'build.ninja')
        build_ninja = []
        with open(build_ninja_filepath, 'r') as build_ninja_file:
            build_ninja = build_ninja_file.readlines()

        if not self.use_shared_libs:
            # Fix a warning with CMake shoving /MT and /MD flags into the same command line
            for index, line in enumerate(build_ninja):
                if line.startswith('  FLAGS ='):
                    build_ninja[index] = line.replace('/MD', '')

        with open(build_ninja_filepath, 'w') as build_ninja_file:
            build_ninja_file.writelines(build_ninja)

        process = subprocess.Popen([util.ninja_path, '-C', build_directory], env=self.environment)
        process.wait()
