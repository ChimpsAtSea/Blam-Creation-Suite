
import os
import subprocess
import build_task_manager
import util

class FFMpegBuildTask(build_task_manager.VisualCPPBuildTask):
    def __init__(self, target_os, arch, toolchain, msvc_target, link_config, _parent_tasks = []):
        super().__init__(f'FFMpegBuildTask {msvc_target} {link_config}', msvc_target, _parent_tasks)
        self.target_os = target_os
        self.arch = arch
        self.toolchain = toolchain
        self.link_config = link_config
        self.msvc_target = msvc_target

    def build(self):
        bash = os.path.join(util.msys2_dir, 'usr/bin/bash')
        shell_script = os.path.join(util.bcs_third_party_dir, 'ffmpeg/build_ffmpeg.sh')
        build_directory = os.path.join(util.bcs_third_party_dir, f'ffmpeg/ffmpeg_build_{self.msvc_target}_{self.link_config}')
        source_directory = os.path.join(util.bcs_third_party_dir, f'ffmpeg/ffmpeg')
        yasm_directory = os.path.join(util.bcs_third_party_dir, f'yasm/yasm_build')

        if os.path.exists(os.path.join(build_directory, 'config.h')):
            return # Don't rebuild

        self.environment['MSYS2_PATH_TYPE'] = 'inherit'

        paths = [
            yasm_directory,
            util.msys2_dir,
            os.path.join(util.bcs_third_party_dir, 'yasm_build/Release'),
        ]
        self.environment['PATH'] = ';'.join([self.environment['PATH']] + paths)

        build_arguments = []
        build_arguments.append(f'--target-os={self.target_os}')
        build_arguments.append(f'--arch={self.arch}')
        build_arguments.append(f'--toolchain={self.toolchain}')
        build_arguments.append('--disable-doc')
        build_arguments.append('--disable-programs')
        build_arguments.append('--enable-cross-compile')
        if self.msvc_target in ['arm', 'arm64']:
            # yasm can't handle this for arm
            build_arguments.append('--disable-asm')
        if self.link_config == 'shared':
            build_arguments.append('--enable-shared')
            build_arguments.append('--disable-static')
        
        self.environment['BuildString'] = f'Building FFMpeg {self.msvc_target} {self.link_config} [{self.target_os}|{self.arch}|{self.toolchain}]'
        self.environment['BuildDirectory'] = build_directory
        self.environment['SourceDirectory'] = source_directory
        self.environment['BuildArguments'] = " ".join(build_arguments)

        if not os.path.exists(build_directory):
            os.makedirs(build_directory)

        process = subprocess.Popen([bash, '-l', shell_script], env=self.environment)
        process.wait()
