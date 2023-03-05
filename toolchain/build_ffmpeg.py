
import os
import subprocess
import build_task_manager
import util

class FFMpegBuildTask(build_task_manager.BuildTask):
    def __init__(self, target_os, arch, toolchain, target_platform, link_config):
        super().__init__(f'FFMpegBuildTask {target_platform} {link_config}')
        self.target_os = target_os
        self.arch = arch
        self.toolchain = toolchain
        self.link_config = link_config
        self.target_platform = target_platform

    def build(self):

        bash = os.path.join(util.msys2_dir, 'usr/bin/bash')
        shell_script = os.path.join(util.bcs_third_party_dir, 'ffmpeg/build_ffmpeg.sh')
        build_directory = os.path.join(util.bcs_third_party_dir, f"ffmpeg/ffmpeg_build_{self.target_platform}_{self.link_config}")
        source_directory = os.path.join(util.bcs_third_party_dir, f"ffmpeg/ffmpeg")

        if os.path.exists(os.path.join(build_directory, "config.h")):
            return # Don't rebuild

        custom_environment = os.environ.copy()
        custom_environment.clear()
        for variable in ['SYSTEMROOT', 'OS']:
            if variable in os.environ:
                custom_environment[variable] = os.environ[variable]

        custom_environment['MSYS2_PATH_TYPE'] = 'inherit'

        paths = [
            os.path.join(util.bcs_third_party_dir, 'msys2-base-x86_64-20230127/msys64/usr/bin'),
            os.path.join(util.bcs_third_party_dir, 'yasm_build/Release'),
            os.path.join(util.ewdk_dir, ''),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.31.31103/bin/HostX86/ARM64'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.31.31103/bin/HostX86/x86'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/Common7/IDE/VC/VCPackages'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/Common7/IDE/CommonExtensions/Microsoft/TestWindow'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/Common7/IDE/CommonExtensions/Microsoft/TeamFoundation/Team Explorer'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/MSBuild/Current/bin/Roslyn'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10//bin//x86'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools//MSBuild/Current/Bin/amd64'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/Common7/IDE/'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/Common7/Tools/'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/Common7/IDE/VC/Linux/bin/ConnectionManagerExe'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10//bin/10.0.22621.0/x86'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10//Tools/bin/i386'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10//tools'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10//tools/ARM64'),
            os.path.join(util.ewdk_dir, 'BuildEnv'),
        ]
        custom_environment['PATH'] = ';'.join(paths)

        includes = [
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/include/10.0.22621.0/ucrt'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/include/10.0.22621.0/um'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/include/10.0.22621.0/shared'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/include/10.0.22621.0/winrt'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/include/10.0.22621.0/cppwinrt'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.31.31103/include'),
        ]
        custom_environment['INCLUDE'] = ';'.join(includes)

        compiler_library = [
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/UnionMetadata/10.0.22621.0'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/References/10.0.22621.0'),
        ]
        custom_environment['LIBPATH'] = ';'.join(compiler_library)

        linker_library = [
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/NETFXSDK/4.8/lib/um/arm64'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/lib/10.0.22621.0/ucrt/arm64'),
            os.path.join(util.ewdk_dir, 'Program Files/Windows Kits/10/lib/10.0.22621.0/um/arm64'),
            os.path.join(util.ewdk_dir, 'Program Files/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.31.31103/lib/arm64'),
        ]
        custom_environment['LIB'] = ';'.join(linker_library)

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        build_arguments = []
        build_arguments.append(f"--target-os={self.target_os}")
        build_arguments.append(f"--arch={self.arch}")
        build_arguments.append(f"--toolchain={self.toolchain}")
        build_arguments.append("--disable-doc")
        build_arguments.append("--disable-programs")
        build_arguments.append("--enable-cross-compile")
        if self.target_platform in ["arm", "arm64"]:
            # yasm can't handle this for arm
            build_arguments.append("--disable-asm")
        if self.link_config == 'shared':
            build_arguments.append("--enable-shared")
            build_arguments.append("--disable-static")
            

        custom_environment['BuildString'] = f'Building FFMpeg {self.target_platform} {self.link_config} [{self.target_os}|{self.arch}|{self.toolchain}]'
        custom_environment['BuildDirectory'] = build_directory
        custom_environment['SourceDirectory'] = source_directory

        process = subprocess.Popen([bash, '-l', shell_script], env=custom_environment)
        process.wait()
