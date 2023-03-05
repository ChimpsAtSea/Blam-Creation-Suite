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

rem Install MSYS2
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\msys2-base-x86_64-20230127.tar.xz curl -L https://github.com/msys2/msys2-installer/releases/download/2023-01-27/msys2-base-x86_64-20230127.tar.xz -o %BCS_DOWNLOAD_CACHE%\msys2-base-x86_64-20230127.tar.xz
IF NOT EXIST %BCS_THIRD_PARTY%\msys2-base-x86_64-20230127\msys64\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\msys2-base-x86_64-20230127.tar.xz -aoa -so | %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y -aos -si -ttar -o%BCS_THIRD_PARTY%\msys2-base-x86_64-20230127\

rem Download CMake
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip curl -L https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-windows-x86_64.zip -o %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip
rem Extract CMake
IF NOT EXIST %BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\cmake-3.25.2-windows-x86_64.zip -o%BCS_THIRD_PARTY%\

rem Download Python
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %BCS_THIRD_PARTY%\python-3.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip -o%BCS_THIRD_PARTY%\python-3.11.1\

rem rem Download GN Build
rem set BCS_GN_REVISION=5e19d2fb166fbd4f6f32147fbb2f497091a54ad8
rem IF NOT EXIST %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip curl -Ls https://chrome-infra-packages.appspot.com/dl/gn/gn/windows-amd64/+/git_revision:%BCS_GN_REVISION% -o %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip
rem rem Extract GN Build
rem IF NOT EXIST %BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip -o%BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\

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

rem Download WinPix3
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\winpixeventruntime.1.0.220810001.nupkg curl -L https://globalcdn.nuget.org/packages/winpixeventruntime.1.0.220810001.nupkg -o %BCS_DOWNLOAD_CACHE%\winpixeventruntime.1.0.220810001.nupkg
rem Extract WinPix3
IF NOT EXIST %BCS_THIRD_PARTY%\winpixeventruntime.1.0.220810001\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -y %BCS_DOWNLOAD_CACHE%\winpixeventruntime.1.0.220810001.nupkg -o%BCS_THIRD_PARTY%\winpixeventruntime.1.0.220810001\

rem Download BusyBox
IF NOT EXIST %BCS_THIRD_PARTY%\busybox mkdir %BCS_THIRD_PARTY%\busybox
IF NOT EXIST %BCS_THIRD_PARTY%\busybox\busybox64.exe curl -L https://frippery.org/files/busybox/busybox64.exe -o %BCS_THIRD_PARTY%\busybox\busybox64.exe

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
set GN_DIR=%BCS_THIRD_PARTY%\gn\gn_build\
rem set NINJA_DIR=%BCS_THIRD_PARTY%\ninja-win-1.11.1
set CMAKE_DIR=%BCS_THIRD_PARTY%\cmake-3.25.2-windows-x86_64\bin
set LLVM_DIR=%BCS_THIRD_PARTY%\llvm
set LLVM_BIN_DIR=%BCS_THIRD_PARTY%\llvm\bin
set MSYS2_DIR=%BCS_THIRD_PARTY%\msys2-base-x86_64-20230127\msys64

rem Build Ninja
set NINJA_DIR=%BCS_THIRD_PARTY%\ninja

IF EXIST %NINJA_DIR%\ninja.exe (
	goto :NinjaBuildEnd
)
if defined EnterpriseWDK (
	goto :EWDKEnvironmentEnd1
)
set INCLUDE=
set LIBPATH=
call %EWDK_DIR%\BuildEnv\SetupBuildEnv.cmd x86_amd64
@echo off
:EWDKEnvironmentEnd1
set _INCLUDE=%INCLUDE%
set _LIBPATH=%LIBPATH%
set _LIB=%LIB%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\ucrt;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\um;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\shared;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\winrt;%INCLUDE%
set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\cppwinrt;%INCLUDE%
set LIBPATH=%EWDK_DIR%\Program Files\Windows Kits\10\UnionMetadata\10.0.22621.0;%LIBPATH%
set LIBPATH=%EWDK_DIR%\Program Files\Windows Kits\10\References\10.0.22621.0;%LIBPATH%
set LIB=%EWDK_DIR%\Program Files\Windows Kits\NETFXSDK\4.8\lib\um\x64;%LIB%
set LIB=%EWDK_DIR%\Program Files\Windows Kits\10\lib\10.0.22621.0\ucrt\x64;%LIB%
set LIB=%EWDK_DIR%\Program Files\Windows Kits\10\lib\10.0.22621.0\um\x64;%LIB%
pushd %NINJA_DIR%
%PYTHON_DIR%\python.exe configure.py --bootstrap
popd
set INCLUDE=%_INCLUDE%
set LIBPATH=%_LIBPATH%
set LIB=%_LIB%
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



rem Install MSYS2 Development Tools
IF NOT EXIST %MSYS2_DIR%\usr\bin\cmp.exe (
	set MSYS2_PATH_TYPE=inherit
	call %MSYS2_DIR%\usr\bin\bash.exe -l "%BCS_ROOT%\toolchain\msys2_firstrun.sh"
)

rem Build YASM (Required for FFMpeg)
IF EXIST %BCS_THIRD_PARTY%\yasm_build\Release\yasm.exe (
	goto :YASMBuildEnd
)
set PATH=%MSYS2_DIR%\usr\bin\;%PATH%
if defined EnterpriseWDK (
	goto :EWDKEnvironmentEnd2
)
set INCLUDE=
set LIBPATH=
call %EWDK_DIR%\BuildEnv\SetupBuildEnv.cmd x86_amd64
@echo off
:EWDKEnvironmentEnd2
set _INCLUDE=%INCLUDE%
set _LIBPATH=%LIBPATH%
set _LIB=%LIB%
rem set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\ucrt;%INCLUDE%
rem set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\um;%INCLUDE%
rem set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\shared;%INCLUDE%
rem set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\winrt;%INCLUDE%
rem set INCLUDE=%EWDK_DIR%\Program Files\Windows Kits\10\include\10.0.22621.0\cppwinrt;%INCLUDE%
rem set LIBPATH=%EWDK_DIR%\Program Files\Windows Kits\10\UnionMetadata\10.0.22621.0;%LIBPATH%
rem set LIBPATH=%EWDK_DIR%\Program Files\Windows Kits\10\References\10.0.22621.0;%LIBPATH%
rem set LIB=%EWDK_DIR%\Program Files\Windows Kits\NETFXSDK\4.8\lib\um\x86;%LIB%
rem set LIB=%EWDK_DIR%\Program Files\Windows Kits\10\lib\10.0.22621.0\ucrt\x86;%LIB%
rem set LIB=%EWDK_DIR%\Program Files\Windows Kits\10\\lib\10.0.22621.0\um\x86;%LIB%
pushd %~dp0
IF NOT EXIST %BCS_THIRD_PARTY%\yasm_build\yasm.sln (
	%CMAKE_DIR%\cmake.exe -S %BCS_THIRD_PARTY%\yasm -B %BCS_THIRD_PARTY%\yasm_build -G "Visual Studio 17 2022" -DCMAKE_CONFIGURATION_TYPES:STRING="Release" -DCMAKE_BUILD_TYPE:STRING="Release" -DBUILD_SHARED_LIBS:BOOL="0" -DYASM_BUILD_TESTS:BOOL="0"
)
IF NOT EXIST %BCS_THIRD_PARTY%\yasm_build\Release\yasm.exe (
	msbuild -m %BCS_THIRD_PARTY%\yasm_build\yasm.sln /property:Configuration=Release /property:Platform=x64 -fl -flp:logfile=MyProjectOutput.log;verbosity=minimal
)
popd
set INCLUDE=%_INCLUDE%
set LIBPATH=%_LIBPATH%
set LIB=%_LIB%
:YASMBuildEnd
set YASM_DIR=%BCS_ROOT%thirdparty\yasm_build\Release

python toolchain/generate_solution.py
