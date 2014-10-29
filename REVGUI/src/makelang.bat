:: ======================================================================================================
:: makelang.bat 			-> creates *.qm files and copies them in the results and build folder (this is the working directory)
:: makelang.bat update		-> updates *.ts files in \localisation folder. call makelang again for builds
::							for editing the language files use "QT Linguist"
:: makelang.bat clear		-> cleares *qm files in project folder and build folder
:: ======================================================================================================
@echo off
:: ======================================================================================================
:: SETTINGS
:: ======================================================================================================
:: define path to lupdate and lrelease
set lcc=C:\Compiler\QtSDK\Desktop\Qt\4.7.3\mingw\bin
:: define results directory
set results=REV_HMI-result
:: define build directory
set builds=REV_HMI-build-desktop
:: ======================================================================================================

if "%1" == "update" goto update
if "%1" == "clear" goto clear
goto build

:: ======================================================================================================
:update
%lcc%\lupdate.exe REV_HMI.pro
goto end
:: ======================================================================================================
:build
%lcc%\lrelease.exe REV_HMI.pro
xcopy localisations\*.qm ..\%results%\ /y /v
xcopy localisations\*.qm ..\%builds%\ /y /v
goto end
:: ======================================================================================================
:clear
del /f /q localisations\*.qm
del /f /q ..\%builds%\*.qm
goto end
:: ======================================================================================================
:end
:: go back to script directory
cd /d %~dp0