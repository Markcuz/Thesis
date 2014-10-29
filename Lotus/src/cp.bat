:: ======================================================================================================
:: cp.bat %1 %2 copies the target to the REV_HMI-result directory and is called after the building procedure
::		%1 is target name, i.e. REV_HMI
::		if %2 is "D", it takes the target from the debug directory and renames it as %target%D. otherwise it takes the release files
:: ======================================================================================================
@echo off
:: ======================================================================================================
:: SETTINGS
:: ======================================================================================================
:: define build directory
set builddir=REV_HMI-build-desktop
:: define results directory
set results=REV_HMI-result
:: ======================================================================================================

if "%1" == "" goto error
set target=%1

if "%2" == "D" goto debug
goto release

:: ======================================================================================================
:debug
set ident=D
set subdir=debug/
goto copy
:: ======================================================================================================
:release
set ident=
set subdir=release/
goto copy
:: ======================================================================================================
:copy
cd ../%builddir%
cd %subdir%
if "%ident%" NEQ "" copy /v /y %target%.exe /b %target%%ident%.exe
xcopy "%target%%ident%.exe" "../../%results%/" /v /f /y /r /i
if "%ident%" NEQ "" del /f %target%%ident%.exe
goto end
:: ======================================================================================================
:error
echo missing arguments: specify target name
goto end
:: ======================================================================================================
:end
:: go back to script directory
cd /d %~dp0

