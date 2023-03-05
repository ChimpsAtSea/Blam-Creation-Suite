#!/bin/bash
echo "$BuildString"
cd $BuildDirectory
$SourceDirectory/configure $BuildArguments --target-os=win32 --arch=aarch64 --toolchain=msvc --disable-doc --disable-programs --enable-cross-compile --disable-asm
make -j
