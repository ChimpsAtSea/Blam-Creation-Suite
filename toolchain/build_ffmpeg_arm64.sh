#!/bin/bash
echo "Building FFMpeg Static Arm64"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_static_arm64
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_static_arm64
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win32 --arch=aarch64 --toolchain=msvc --disable-doc --disable-programs --enable-cross-compile --disable-asm
make -j32

echo "Building FFMpeg Shared Arm64"
mkdir /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_shared_arm64
cd /e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg_build_shared_arm64
/e/GitHub/Blam-Creation-Suite/thirdparty/ffmpeg/configure --target-os=win32 --arch=aarch64 --toolchain=msvc --disable-doc --enable-shared --disable-static --disable-programs --enable-cross-compile --disable-asm
make -j32
