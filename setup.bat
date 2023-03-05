@echo off
cls

IF DEFINED APPVEYOR echo Setup recognised AppVeyor

IF NOT DEFINED BCS_ROOT set BCS_ROOT=%~dp0
IF NOT DEFINED BCS_THIRD_PARTY set BCS_THIRD_PARTY=%BCS_ROOT%thirdparty
IF NOT DEFINED BCS_DOWNLOAD_CACHE set BCS_DOWNLOAD_CACHE=%BCS_ROOT%downloadcache

rem Install 7z
set _7Z_DIR=%BCS_THIRD_PARTY%\7-Zip\7z2201-x64\
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi curl -L --show-error https://www.7-zip.org/a/7z2201-x64.msi -o %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi
IF NOT EXIST %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe msiexec /a %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi /qn TARGETDIR=%_7Z_DIR%

rem Download Python
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %BCS_THIRD_PARTY%\python-3.11.1\ %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip -o%BCS_THIRD_PARTY%\python-3.11.1\
set PYTHON_DIR=%BCS_THIRD_PARTY%\python-3.11.1

rem rem Download CMake
rem IF NOT EXIST %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip curl -L https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-windows-x86_64.zip -o %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip
rem rem Extract CMake
rem IF NOT EXIST %BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\ %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip -o%BCS_THIRD_PARTY%\

rem Download Musl
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz curl -L https://musl.cc/i686-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz curl -L https://musl.cc/x86_64-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\aarch64-linux-musl-native.tgz curl -L https://musl.cc/aarch64-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\aarch64-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\arm-linux-musleabi-native.tgz curl -L https://musl.cc/arm-linux-musleabi-native.tgz -o %BCS_DOWNLOAD_CACHE%\arm-linux-musleabi-native.tgz

rem Extract Musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\i686-linux-musl-native.tar %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\i686-linux-musl-native %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\i686-linux-musl-native.tar -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\x86_64-linux-musl-native.tar %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\x86_64-linux-musl-native %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\x86_64-linux-musl-native.tar -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\aarch64-linux-musl-native.tar %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\aarch64-linux-musl-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\aarch64-linux-musl-native %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\aarch64-linux-musl-native.tar -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\arm-linux-musleabi-native.tar %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\arm-linux-musleabi-native.tgz -o%BCS_THIRD_PARTY%\linux-musl
IF NOT EXIST %BCS_THIRD_PARTY%\linux-musl\arm-linux-musleabi-native %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\linux-musl\arm-linux-musleabi-native.tar -o%BCS_THIRD_PARTY%\linux-musl

rem Download WASI
rem IF NOT EXIST %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-17/wasi-sysroot-17.0.tar.gz -o %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz
rem IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot-17.0.tar %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\
rem IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot-17.0.tar -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\

rem Download Custom WASI with Exception Support see https://github.com/WebAssembly/wasi-sdk/pull/198
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz curl -L https://github.com/ChimpsAtSea/wasi-sdk/releases/download/wasi-sdk-17-exceptions/wasi-sysroot-17.0.tar.gz -o %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz
IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sdk-17-exceptions.tar %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\
IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot %_7Z_DIR%Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sdk-17-exceptions.tar -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\

set GN_DIR=%BCS_THIRD_PARTY%\gn\gn_build\
rem set CMAKE_DIR=%BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\bin
rem set LLVM_DIR=%BCS_THIRD_PARTY%\llvm
rem set LLVM_BIN_DIR=%BCS_THIRD_PARTY%\llvm\bin
set NINJA_DIR=%BCS_THIRD_PARTY%\ninja\ninja_build

set BCS_SETUP_ENVIRONMENT=1

%PYTHON_DIR%/python toolchain/generate_solution.py
