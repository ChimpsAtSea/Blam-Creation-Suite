@echo off
cls

setlocal enabledelayedexpansion

if defined BOB_DIRECTORY (
    for /f "tokens=*" %%a in ('dir /AL /b %cd% 2^>nul') do (
        if "%%a" == "bob" (set bob_is_symlink=1)
    )
    if defined bob_is_symlink (
        echo Using Bob symbolic link
    ) else (
        echo Creating Bob symbolic link
	if exist bob (
            echo Nuking existing bob directory
            rm -rf bob
        )
        mklink /d /j bob %BOB_DIRECTORY%\
    )
)

endlocal

IF NOT DEFINED bob_root set bob_root=%~dp0bob\
IF NOT DEFINED bob_project_root set bob_project_root=%~dp0

IF DEFINED BOB_DOWNLOAD_CACHE set bob_download_cache_dir=%BOB_DOWNLOAD_CACHE%
IF NOT DEFINED bob_download_cache_dir set bob_download_cache_dir=%bob_root%downloadcache
IF NOT EXIST %bob_download_cache_dir% mkdir %bob_download_cache_dir%

call bob/setup.bat --bob-solution-pretty-name "Blam Creation Suite" --bob-solution-namespace "blamcreationsuite" %*
