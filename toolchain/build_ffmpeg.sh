#!/bin/bash
echo "Building FFMpeg Static"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_static_build
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_static_build
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win64 --arch=x86_64 --toolchain=msvc --disable-doc --disable-programs
make -j32

echo "Building FFMpeg Shared"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_shared_build
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_shared_build
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win64 --arch=x86_64 --toolchain=msvc --disable-doc --enable-shared --disable-static --disable-programs
make -j32
