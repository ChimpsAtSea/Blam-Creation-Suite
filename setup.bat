@echo off
cls

IF DEFINED APPVEYOR echo Setup recognised AppVeyor

IF NOT DEFINED bcs_root set bcs_root=%~dp0
IF NOT DEFINED bcs_third_party_dir set bcs_third_party_dir=%bcs_root%thirdparty
IF DEFINED BCS_DOWNLOAD_CACHE set bcs_download_cache_dir=%BCS_DOWNLOAD_CACHE%
IF NOT DEFINED bcs_download_cache_dir set bcs_download_cache_dir=%bcs_root%downloadcache
IF NOT EXIST %bcs_download_cache_dir% mkdir %bcs_download_cache_dir%

rem Install 7z
set bcs_7z_dir=%bcs_third_party_dir%\7-Zip\7z2201-x64
IF NOT EXIST %bcs_download_cache_dir%\7z2201-x64.msi curl -L --show-error https://www.7-zip.org/a/7z2201-x64.msi -o %bcs_download_cache_dir%\7z2201-x64.msi
IF NOT EXIST %bcs_third_party_dir%\7z2201-x64\Files\7-Zip\7z.exe msiexec /a %bcs_download_cache_dir%\7z2201-x64.msi /qn TARGETDIR=%bcs_7z_dir%\

rem Download Python
IF NOT EXIST %bcs_download_cache_dir%\python-3.11.1-embed-amd64.zip curl -L https://www.python.org/ftp/python/3.11.1/python-3.11.1-embed-amd64.zip -o %bcs_download_cache_dir%\python-3.11.1-embed-amd64.zip
rem Extract Python
IF NOT EXIST %bcs_third_party_dir%\python-3.11.1\ %bcs_7z_dir%\Files\7-Zip\7z.exe x -y %bcs_download_cache_dir%\python-3.11.1-embed-amd64.zip -o%bcs_third_party_dir%\python-3.11.1\
set bcs_python_dir=%bcs_third_party_dir%\python-3.11.1

%bcs_python_dir%/python toolchain/python/setup_generate_solution.py %*
