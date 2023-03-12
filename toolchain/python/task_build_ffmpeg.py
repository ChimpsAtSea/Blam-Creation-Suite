import os
import subprocess
from task_manager import VisualCPPBuildTask
import library_util as util

class FFmpegBuildTask(VisualCPPBuildTask):
    def __init__(self, target_os, arch, toolchain, msvc_target, link_config, _parent_tasks = []):
        super().__init__(f'FFmpegBuildTask {msvc_target} {link_config}', msvc_target, _parent_tasks)
        self.target_os = target_os
        self.arch = arch
        self.toolchain = toolchain
        self.link_config = link_config
        self.msvc_target = msvc_target
        self.output_libraries = list[str]()
        self.output_binaries = list[str]()

    def build(self):
        super().build()
        
        bash = os.path.join(util.bcs_msys2_dir, 'usr/bin/bash')
        shell_script = os.path.join(util.bcs_third_party_dir, 'ffmpeg/build_ffmpeg.sh')
        build_directory = os.path.join(util.bcs_third_party_dir, f'ffmpeg/ffmpeg_build_{self.msvc_target}_{self.link_config}')
        source_directory = os.path.join(util.bcs_third_party_dir, f'ffmpeg/ffmpeg')
        yasm_directory = os.path.join(util.bcs_third_party_dir, f'yasm/yasm_build')

        if self.link_config == 'shared':
            self.output_libraries = [
                os.path.join(build_directory, 'libavcodec/avcodec.lib'),
                os.path.join(build_directory, 'libavdevice/avdevice.lib'),
                os.path.join(build_directory, 'libavfilter/avfilter.lib'),
                os.path.join(build_directory, 'libavformat/avformat.lib'),
                os.path.join(build_directory, 'libavutil/avutil.lib'),
                os.path.join(build_directory, 'libswresample/swresample.lib'),
                os.path.join(build_directory, 'libswscale/swscale.lib') ]
            self.output_binaries = [
                os.path.join(build_directory, 'libavcodec/avcodec-60.dll'),
                os.path.join(build_directory, 'libavcodec/avcodec.dll'),
                os.path.join(build_directory, 'libavdevice/avdevice-60.dll'),
                os.path.join(build_directory, 'libavdevice/avdevice.dll'),
                os.path.join(build_directory, 'libavfilter/avfilter-9.dll'),
                os.path.join(build_directory, 'libavfilter/avfilter.dll'),
                os.path.join(build_directory, 'libavformat/avformat-60.dll'),
                os.path.join(build_directory, 'libavformat/avformat.dll'),
                os.path.join(build_directory, 'libavutil/avutil-58.dll'),
                os.path.join(build_directory, 'libavutil/avutil.dll'),
                os.path.join(build_directory, 'libswresample/swresample-4.dll'),
                os.path.join(build_directory, 'libswresample/swresample.dll'),
                os.path.join(build_directory, 'libswscale/swscale-7.dll'),
                os.path.join(build_directory, 'libswscale/swscale.dll') ]
        else:
            self.output_libraries = [
                os.path.join(build_directory, 'libavcodec/libavcodec.a'),
                os.path.join(build_directory, 'libavdevice/libavdevice.a'),
                os.path.join(build_directory, 'libavfilter/libavfilter.a'),
                os.path.join(build_directory, 'libavformat/libavformat.a'),
                os.path.join(build_directory, 'libavutil/libavutil.a'),
                os.path.join(build_directory, 'libswresample/libswresample.a'),
                os.path.join(build_directory, 'libswscale/libswscale.a') ]

        if os.path.exists(os.path.join(build_directory, 'config.h')):
            return # Don't rebuild

        self.environment['MSYS2_PATH_TYPE'] = 'inherit'

        paths = [
            yasm_directory,
            util.bcs_msys2_dir,
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
