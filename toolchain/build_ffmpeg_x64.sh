#!/bin/bash
echo "Building FFMpeg Static x64"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_static_x64
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_static_x64
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win64 --arch=x86_64 --toolchain=msvc --disable-doc --disable-programs
make -j32

echo "Building FFMpeg Shared x64"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_shared_x64
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_shared_x64
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win64 --arch=x86_64 --toolchain=msvc --disable-doc --enable-shared --disable-static --disable-programs
make -j32
