#!/bin/bash
echo "Building FFMpeg Static x86"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_static_x86
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_static_x86
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win32 --arch=x86_32 --toolchain=msvc --disable-doc --disable-programs
make -j32

echo "Building FFMpeg Shared x86"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_shared_x86
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_shared_x86
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win32 --arch=x86_32 --toolchain=msvc --disable-doc --enable-shared --disable-static --disable-programs
make -j32
