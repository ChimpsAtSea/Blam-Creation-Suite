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

rem Install Standard LLVM
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/LLVM-15.0.6-win64.exe -o %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/llvm-15.0.6.src.tar.xz -o %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz
rem Extract LLVM Binaries
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\bin\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe -o%BCS_THIRD_PARTY%\llvm\
rem Extract LLVM Source Code
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\llvm-15.0.6.src\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz -aoa -so | %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y -aos -si -ttar -o%BCS_THIRD_PARTY%\llvm\

rem Download Ninja
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip curl -L https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-win.zip -o %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip
rem Extract Ninja
IF NOT EXIST %BCS_THIRD_PARTY%\ninja-win-1.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip -o%BCS_THIRD_PARTY%\ninja-win-1.11.1\

rem Download Python
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %BCS_THIRD_PARTY%\python-3.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip -o%BCS_THIRD_PARTY%\python-3.11.1\

rem Download GN Build
set BCS_GN_REVISION=5e19d2fb166fbd4f6f32147fbb2f497091a54ad8
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip curl -Ls https://chrome-infra-packages.appspot.com/dl/gn/gn/windows-amd64/+/git_revision:%BCS_GN_REVISION% -o %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip
rem Extract GN Build
IF NOT EXIST %BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip -o%BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\

rem Download Windows 10 EWDK
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso curl -L https://software-static.download.prss.microsoft.com/dbazure/988969d5-f34g-4e03-ac9d-1f9786c66749/EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso
rem Extract Windows 10 EWDK
IF NOT EXIST %BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o%BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759\

rem Download Musl
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz curl -L https://musl.cc/i686-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz curl -L https://musl.cc/x86_64-linux-musl-native.tgz -o %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz

rem Extract Musl
IF NOT EXIST %BCS_THIRD_PARTY%\i686-linux-musl-native.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\i686-linux-musl-native.tgz -o%BCS_THIRD_PARTY%
IF NOT EXIST %BCS_THIRD_PARTY%\x86_64-linux-musl-native.tar %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\x86_64-linux-musl-native.tgz -o%BCS_THIRD_PARTY%
IF NOT EXIST %BCS_THIRD_PARTY%\i686-linux-musl-native %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\i686-linux-musl-native.tar -o%BCS_THIRD_PARTY%
IF NOT EXIST %BCS_THIRD_PARTY%\x86_64-linux-musl-native %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_THIRD_PARTY%\x86_64-linux-musl-native.tar -o%BCS_THIRD_PARTY%

rem Download TBB
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\oneapi-tbb-2021.7.0-win.zip curl -L https://github.com/oneapi-src/oneTBB/releases/download/v2021.7.0/oneapi-tbb-2021.7.0-win.zip -o%BCS_DOWNLOAD_CACHE%\oneapi-tbb-2021.7.0-win.zip

rem Extract TBB
IF NOT EXIST %BCS_THIRD_PARTY%\oneapi-tbb-2021.7.0 %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\oneapi-tbb-2021.7.0-win.zip -o%BCS_THIRD_PARTY%

rem Download BusyBox
IF NOT EXIST %BCS_THIRD_PARTY%\busybox64.exe curl -L https://frippery.org/files/busybox/busybox64.exe -o %BCS_THIRD_PARTY%\busybox64.exe

set PYTHON_DIR=%BCS_THIRD_PARTY%\python-3.11.1
set _7Z_DIR=%BCS_THIRD_PARTY%\7z2201-x64
set EWDK_DIR=%BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759
set GN_DIR=%BCS_THIRD_PARTY%\gn-windows-amd64-5e19d2fb166fbd4f6f32147fbb2f497091a54ad8
set LLVM_DIR=%BCS_THIRD_PARTY%\llvm
set NINJA_DIR=%BCS_THIRD_PARTY%\ninja-win-1.11.1
set LLVM_BIN_DIR=%BCS_THIRD_PARTY%\llvm\bin
	
set PATH_PREPEND=
IF NOT DEFINED BCS_SETUP_ENVIRONMENT (
	setlocal EnableDelayedExpansion 

	echo Setting BCS Environment
	
	echo PYTHON_DIR: %PYTHON_DIR%\
	echo 7Z_DIR:     %_7Z_DIR%\
	echo EWDK_DIR:   %EWDK_DIR%\
	echo GN_DIR:     %GN_DIR%\
	echo LLVM_DIR:   %LLVM_DIR%\
	echo NINJA_DIR:  %NINJA_DIR%\
	
	set PATH_PREPEND=%PYTHON_DIR%\;%_7Z_DIR%\;%EWDK_DIR%\;%GN_DIR%\;%LLVM_DIR%\;%NINJA_DIR%\;%LLVM_BIN_DIR%\;
	
	set BCS_SETUP_ENVIRONMENT=1
)
set PATH=%PATH_PREPEND%%PATH%

gn gen solution/windows-debug-x86     --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""   target_os="""win""" target_config="""debug""""
gn gen solution/windows-debug-x64     --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""   target_os="""win""" target_config="""debug"""
gn gen solution/windows-debug-arm     --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm"""   target_os="""win""" target_config="""debug"""
gn gen solution/windows-debug-arm64   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm64""" target_os="""win""" target_config="""debug"""
gn gen solution/windows-test-x86      --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""   target_os="""win""" target_config="""test"""
gn gen solution/windows-test-x64      --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""   target_os="""win""" target_config="""test"""
gn gen solution/windows-test-arm      --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm"""   target_os="""win""" target_config="""test"""
gn gen solution/windows-test-arm64    --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm64""" target_os="""win""" target_config="""test"""
gn gen solution/windows-release-x86   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86"""   target_os="""win""" target_config="""release"""
gn gen solution/windows-release-x64   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64"""   target_os="""win""" target_config="""release"""
gn gen solution/windows-release-arm   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm"""   target_os="""win""" target_config="""release"""
gn gen solution/windows-release-arm64 --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""arm64""" target_os="""win""" target_config="""test"""

gn gen solution/linux-debug-x86     --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86""" target_os="""linux""" target_config="""debug""""
gn gen solution/linux-debug-x64     --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64""" target_os="""linux""" target_config="""debug"""
gn gen solution/linux-test-x86      --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86""" target_os="""linux""" target_config="""test"""
gn gen solution/linux-test-x64      --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64""" target_os="""linux""" target_config="""test"""
gn gen solution/linux-release-x86   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x86""" target_os="""linux""" target_config="""release"""
gn gen solution/linux-release-x64   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""x64""" target_os="""linux""" target_config="""release"""

gn gen solution/webassembly-debug-wasm32   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm32""" target_os="""wasm""" target_config="""debug""""
gn gen solution/webassembly-debug-wasm64   --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm64""" target_os="""wasm""" target_config="""debug""""
gn gen solution/webassembly-test-wasm32    --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm32""" target_os="""wasm""" target_config="""test"""
gn gen solution/webassembly-test-wasm64    --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm64""" target_os="""wasm""" target_config="""test"""
gn gen solution/webassembly-release-wasm32 --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm32""" target_os="""wasm""" target_config="""release"""
gn gen solution/webassembly-release-wasm64 --ide=vs2022 --ninja-executable="%NINJA_DIR%\ninja.exe" --args="bcs_third_party="""%BCS_THIRD_PARTY%""" target_cpu="""wasm64""" target_os="""wasm""" target_config="""release"""

python toolchain/generate_solution.py
