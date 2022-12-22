@echo off
cls

set BCS_ROOT=%~dp0
set BCS_THIRD_PARTY=%~dp0thirdparty
set BCS_DOWNLOAD_CACHE=%~dp0downloadcache

IF NOT EXIST %BCS_DOWNLOAD_CACHE%\ mkdir %BCS_DOWNLOAD_CACHE%
IF NOT EXIST %BCS_THIRD_PARTY%\7z2201-x64\ mkdir %BCS_THIRD_PARTY%\7z2201-x64

rem Install 7z
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi curl -L --show-error https://www.7-zip.org/a/7z2201-x64.msi -o %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi
IF NOT EXIST %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe msiexec /a %BCS_DOWNLOAD_CACHE%\7z2201-x64.msi /qn TARGETDIR=%BCS_THIRD_PARTY%\7z2201-x64

rem Install Standard LLVM
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/LLVM-15.0.6-win64.exe -o %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz curl -L https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.6/llvm-15.0.6.src.tar.xz -o %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz
rem Extract LLVM Binaries
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\bin\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x %BCS_DOWNLOAD_CACHE%\LLVM-15.0.6-win64.exe -o%BCS_THIRD_PARTY%\llvm\
rem Extract LLVM Source Code
IF NOT EXIST %BCS_THIRD_PARTY%\llvm\llvm-15.0.6.src\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x %BCS_DOWNLOAD_CACHE%\llvm-15.0.6.src.tar.xz -aoa -so | %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x -aos -si -ttar -o%BCS_THIRD_PARTY%\llvm\

rem Download Ninja
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip curl -L https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-win.zip -o %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip
rem Extract Ninja
IF NOT EXIST %BCS_THIRD_PARTY%\ninja-win-1.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x %BCS_DOWNLOAD_CACHE%\ninja-win-1.11.1.zip -o%BCS_THIRD_PARTY%\ninja-win-1.11.1\

rem Download Python
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %BCS_THIRD_PARTY%\python-3.11.1\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x %BCS_DOWNLOAD_CACHE%\python-3.11.1-embed-amd64.zip -o%BCS_THIRD_PARTY%\python-3.11.1\

rem Download GN Build
set BCS_GN_REVISION=5e19d2fb166fbd4f6f32147fbb2f497091a54ad8
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip curl -Ls https://chrome-infra-packages.appspot.com/dl/gn/gn/windows-amd64/+/git_revision:%BCS_GN_REVISION% -o %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip
rem Extract GN Build
IF NOT EXIST %BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x %BCS_DOWNLOAD_CACHE%\gn-windows-amd64-%BCS_GN_REVISION%.zip -o%BCS_THIRD_PARTY%\gn-windows-amd64-%BCS_GN_REVISION%\

rem Download Windows 10 EWDK
IF NOT EXIST %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso curl -L https://software-static.download.prss.microsoft.com/dbazure/988969d5-f34g-4e03-ac9d-1f9786c66749/EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso
rem Extract Windows 10 EWDK
IF NOT EXIST %BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759\ %BCS_THIRD_PARTY%\7z2201-x64\Files\7-Zip\7z.exe x %BCS_DOWNLOAD_CACHE%\EWDK_ni_release_svc_prod1_22621_220804-1759.iso -o%BCS_THIRD_PARTY%\EWDK_ni_release_svc_prod1_22621_220804-1759\
