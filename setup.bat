@echo off
cls

IF DEFINED APPVEYOR echo Setup recognised AppVeyor

IF NOT DEFINED BCS_ROOT set BCS_ROOT=%~dp0
IF NOT DEFINED BCS_THIRD_PARTY set BCS_THIRD_PARTY=%BCS_ROOT%thirdparty
IF NOT DEFINED BCS_DOWNLOAD_CACHE set BCS_DOWNLOAD_CACHE=%BCS_ROOT%downloadcache

IF NOT EXIST %BCS_DOWNLOAD_CACHE%\ mkdir %BCS_DOWNLOAD_CACHE%
IF NOT EXIST %BCS_THIRD_PARTY%\7z2201-x64\ mkdir %BCS_THIRD_PARTY%\7z2201-x64

rem Install 7z
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi curl -L --show-error https://www.7-zip.org/a/7z2201-x64.msi -o %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi
IF NOT EXIST %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe msiexec /a %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi /qn TARGETDIR=%BCS_THIRD_PARTY%\7z2201-x64

rem Download Windows 10 EWDK
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso curl -L https://software-static.download.prss.microsoft.com/dbazure/988969d5-f34g-4e03-ac9d-1f9786c66749/EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso
rem Extract Windows 10 EWDK
IF NOT EXIST %BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o%BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759\

rem Install Standard LLVM
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/LLVM-15.0.6-win64.exe -o %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/llvm-15.0.6.src.tar.xz -o %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz
rem Extract LLVM Binaries
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\bin\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe -o%BCS_THIRD_PARTY%\llvm\
rem Extract LLVM Source Code
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\llvm-15.0.6.src\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz -aoa -so | %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y -aos -si -ttar -o%BCS_THIRD_PARTY%\llvm\


rem Download CMake
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip curl -L https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-windows-x86_64.zip -o %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip
rem Extract CMake
IF NOT EXIST %BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip -o%BCS_THIRD_PARTY%\

rem Download Python
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %BCS_THIRD_PARTY%\python-3.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip -o%BCS_THIRD_PARTY%\python-3.11.1\

rem Download GN Build
set BCS_GN_REVISION=5e19d2fb166fbd4f6f32147fbb2f497091a54ad8
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip curl -Ls https://chrome-infra-packages.appspot.com/dl/gn/gn/windows-amd64/+/git_revision:%BCS_GN_REVISION% -o %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip
rem Extract GN Build
IF NOT EXIST %BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip -o%BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\

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

rem Download BusyBox
IF NOT EXIST %BCS_THIRD_PARTY%\busybox64.exe curl -L https://frippery.org/files/busybox/busybox64.exe -o %BCS_THIRD_PARTY%\busybox64.exe

rem Download WASI
rem IF NOT EXIST %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-17/wasi-sysroot-17.0.tar.gz -o %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz
rem IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot-17.0.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\wasi-sysroot-17.0.tar.gz -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\
rem IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot-17.0.tar -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\

rem Download Custom WASI with Exception Support see https://github.com/WebAssembly/wasi-sdk/pull/198
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz curl -L https://github.com/ChimpsAtSea/wasi-sdk/releases/download/wasi-sdk-17-exceptions/wasi-sysroot-17.0.tar.gz -o %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz
IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sdk-17-exceptions.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\wasi-sdk-17-exceptions.tar.gz -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\
IF NOT EXIST %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sysroot %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\wasi-sysroot-17.0\wasi-sdk-17-exceptions.tar -o%BCS_THIRD_PARTY%\wasi-sysroot-17.0\

rem Download Ninja
rem IF NOT EXIST %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip curl -L https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-win.zip -o %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip
rem Extract Ninja
rem IF NOT EXIST %BCS_THIRD_PARTY%\ninja-win-1.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip -o%BCS_THIRD_PARTY%\ninja-win-1.11.1\

set PYTHON_DIR=%BCS_THIRD_PARTY%\python-3.11.1
set _7Z_DIR=%BCS_THIRD_PARTY%\7z2201-x64
set EWDK_DIR=%BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759
set GN_DIR=%BCS_THIRD_PARTY%\gn-windows-amd64-5e19d2fb166fbd4f6f32147fbb2f497091a54ad8
rem set NINJA_DIR=%BCS_THIRD_PARTY%\ninja-win-1.11.1
set CMAKE_DIR=%BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\bin
set LLVM_DIR=%BCS_THIRD_PARTY%\llvm
set LLVM_BIN_DIR=%BCS_THIRD_PARTY%\llvm\bin

rem Build Ninja
set NINJA_DIR=%BCS_THIRD_PARTY%\ninja\

IF EXIST %NINJA_DIR%\ninja.exe (
	goto :NinjaBuildEnd
)
if defined EnterpriseWDK (
	goto :EWDKEnvironmentEnd
)
set INCLUDE=
set LIBPATH=
call %EWDK_DIR%\BuildEnv\SetupBuildEnv.cmd
@echo off
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\ucrt;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\um;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\shared;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\winrt;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\cppwinrt;%INCLUDE%
set LIBPATH=%EWDK_DIR%\Program Files\Windows Kits\10\UnionMetadata\10.0.22621.0;%LIBPATH%
set LIBPATH=%EWDK_DIR%\Program Files\Windows Kits\10\References\10.0.22621.0;%LIBPATH%
set LIB=%EWDK_DIR%\Program Files\Windows Kits\NETFXSDK\4.8\lib\um\x86;%LIB%
set LIB=%EWDK_DIR%\Program Files\Windows Kits\10\lib\10.0.22621.0\ucrt\x86;%LIB%
set LIB=%EWDK_DIR%\Program Files\Windows Kits\10\\lib\10.0.22621.0\\um\x86;%LIB%
:EWDKEnvironmentEnd
pushd %NINJA_DIR%
%PYTHON_DIR%\python.exe configure.py --bootstrap
popd
:NinjaBuildEnd

set PATH_PREPEND=
IF NOT DEFINED BCS_SETUP_ENVIRONMENT (

	echo Setting BCS Environment
	
	echo PYTHON_DIR: %PYTHON_DIR%\
	echo 7Z_DIR:     %_7Z_DIR%\
	echo EWDK_DIR:   %EWDK_DIR%\
	echo GN_DIR:     %GN_DIR%\
	echo NINJA_DIR:  %NINJA_DIR%\
	echo CMAKE_DIR:  %CMAKE_DIR%\
	echo LLVM_DIR:   %LLVM_DIR%\
	echo LLVM_BIN_DIR:   %LLVM_DIR%\
	
	set PATH_PREPEND=%PYTHON_DIR%\;%_7Z_DIR%\;%EWDK_DIR%\;%GN_DIR%\;%NINJA_DIR%\;%CMAKE_DIR%\;%LLVM_DIR%\;%LLVM_BIN_DIR%\;
	
	set BCS_SETUP_ENVIRONMENT=1
)
set PATH=%PATH_PREPEND%%PATH%

gn gen solution/windows-debug-x86          --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""    target_os="""win"""   target_config="""debug""""
gn gen solution/windows-debug-x64          --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""    target_os="""win"""   target_config="""debug"""
gn gen solution/windows-debug-arm          --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm"""    target_os="""win"""   target_config="""debug"""
gn gen solution/windows-debug-arm64        --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm64"""  target_os="""win"""   target_config="""debug"""
gn gen solution/windows-test-x86           --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""    target_os="""win"""   target_config="""test"""
gn gen solution/windows-test-x64           --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""    target_os="""win"""   target_config="""test"""
gn gen solution/windows-test-arm           --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm"""    target_os="""win"""   target_config="""test"""
gn gen solution/windows-test-arm64         --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm64"""  target_os="""win"""   target_config="""test"""
gn gen solution/windows-release-x86        --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""    target_os="""win"""   target_config="""release"""
gn gen solution/windows-release-x64        --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""    target_os="""win"""   target_config="""release"""
gn gen solution/windows-release-arm        --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm"""    target_os="""win"""   target_config="""release"""
gn gen solution/windows-release-arm64      --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm64"""  target_os="""win"""   target_config="""test"""

gn gen solution/linux-debug-x86            --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""    target_os="""linux""" target_config="""debug""""
gn gen solution/linux-debug-x64            --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""    target_os="""linux""" target_config="""debug"""
gn gen solution/linux-test-x86             --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""    target_os="""linux""" target_config="""test"""
gn gen solution/linux-test-x64             --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""    target_os="""linux""" target_config="""test"""
gn gen solution/linux-release-x86          --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""    target_os="""linux""" target_config="""release"""
gn gen solution/linux-release-x64          --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""    target_os="""linux""" target_config="""release"""

gn gen solution/webassembly-debug-wasm32   --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm32""" target_os="""wasm"""  target_config="""debug""""
rem gn gen solution/webassembly-debug-wasm64   --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm64""" target_os="""wasm"""  target_config="""debug""""
gn gen solution/webassembly-test-wasm32    --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm32""" target_os="""wasm"""  target_config="""test"""
rem gn gen solution/webassembly-test-wasm64    --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm64""" target_os="""wasm"""  target_config="""test"""
gn gen solution/webassembly-release-wasm32 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm32""" target_os="""wasm"""  target_config="""release"""
rem gn gen solution/webassembly-release-wasm64 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm64""" target_os="""wasm"""  target_config="""release"""

python toolchain/generate_solution.py
