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

%PYTHON_DIR%/python toolchain/generate_solution.py %*
