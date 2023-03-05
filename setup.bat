@echo off
cls

IF DEFINED APPVEYOR echo Setup recognised AppVeyor

IF NOT DEFINED BCS_ROOT set BCS_ROOT=%~dp0
IF NOT DEFINED BCS_THIRD_PARTY set BCS_THIRD_PARTY=%BCS_ROOT%thirdparty
IF NOT DEFINED BCS_DOWNLOAD_CACHE set BCS_DOWNLOAD_CACHE=%BCS_ROOT%downloadcache

rem Download Python
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %BCS_THIRD_PARTY%\python-3.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip -o%BCS_THIRD_PARTY%\python-3.11.1\
set PYTHON_DIR=%BCS_THIRD_PARTY%\python-3.11.1

rem Install Standard LLVM
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/LLVM-15.0.6-win64.exe -o %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/llvm-15.0.6.src.tar.xz -o %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz
rem Extract LLVM Binaries
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\bin\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe -o%BCS_THIRD_PARTY%\llvm\
rem Extract LLVM Source Code
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\llvm-15.0.6.src\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz -aoa -so | %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y -aos -si -ttar -o%BCS_THIRD_PARTY%\llvm\

rem Install MSYS2
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\msys2-base-x86_64-20230127.tar.xz curl -L https://github.com/msys2/msys2-installer/releases/download/2023-01-27/msys2-base-x86_64-20230127.tar.xz -o %BCS_DOWNLOAD_CACHE%\msys2-base-x86_64-20230127.tar.xz
IF NOT EXIST %BCS_THIRD_PARTY%\msys2-base-x86_64-20230127\msys64\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\msys2-base-x86_64-20230127.tar.xz -aoa -so | %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y -aos -si -ttar -o%BCS_THIRD_PARTY%\msys2-base-x86_64-20230127\

rem Download CMake
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip curl -L https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-windows-x86_64.zip -o %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip
rem Extract CMake
IF NOT EXIST %BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip -o%BCS_THIRD_PARTY%\

rem Download Musl
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz curl -L https://musl.cc/i686-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz curl -L https://musl.cc/x86_64-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\aarch64-linux-musl-native.tgz curl -L https://musl.cc/aarch64-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\aarch64-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\arm-linux-musleabi-native.tgz curl -L https://musl.cc/arm-linux-musleabi-native.tgz -o %BCS_DOWNLOAD_CACHE%\arm-linux-musleabi-native.tgz

rem Extract Musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\i686-linux-musl-native.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\i686-linux-musl-native %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\i686-linux-musl-native.tar -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\x86_64-linux-musl-native.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\x86_64-linux-musl-native %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\x86_64-linux-musl-native.tar -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\aarch64-linux-musl-native.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\aarch64-linux-musl-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\aarch64-linux-musl-native %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\aarch64-linux-musl-native.tar -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\arm-linux-musleabi-native.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\arm-linux-musleabi-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\arm-linux-musleabi-native %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\arm-linux-musleabi-native.tar -o%BCS_THIRD_PARTY%\linux-musl

rem Download WASI
rem IF NOT EXIST %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-17/wasi-sysroot-17.0.tar.gz -o %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz
rem IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot-17.0.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\
rem IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot-17.0.tar -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\

rem Download Custom WASI with Exception Support see https://github.com/WebAssembly/wasi-sdk/pull/198
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz curl -L https://github.com/ChimpsAtSea/wasi-sdk/releases/download/wasi-sdk-17-exceptions/wasi-sysroot-17.0.tar.gz -o %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz
IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sdk-17-exceptions.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\
IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sdk-17-exceptions.tar -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\

set GN_DIR=%BCS_THIRD_PARTY%\gn\gn_build\
set CMAKE_DIR=%BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\bin
set LLVM_DIR=%BCS_THIRD_PARTY%\llvm
set LLVM_BIN_DIR=%BCS_THIRD_PARTY%\llvm\bin
set MSYS2_DIR=%BCS_THIRD_PARTY%\msys2-base-x86_64-20230127\msys64
set NINJA_DIR=%BCS_THIRD_PARTY%\ninja\ninja_build

set BCS_SETUP_ENVIRONMENT=1

rem Install MSYS2 Development Tools
IF NOT EXIST %MSYS2_DIR%\usr\bin\cmp.exe (
	set MSYS2_PATH_TYPE=inherit
	call %MSYS2_DIR%\usr\bin\bash.exe -l "%BCS_ROOT%\toolchain\msys2_firstrun.sh"
)

python toolchain/generate_solution.py
