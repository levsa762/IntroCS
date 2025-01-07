@echo off
setlocal

if "%~1"=="" (
    echo Usage: %0 folder_name
    exit /b 1
)

set "folder=%~1"

rem Change to the specified folder
pushd "%folder%" || exit /b 1

rem Find a .cpp file and extract the base name without _Q1
for %%f in (*.cpp) do (
    set "file_name=%%~nf"
    set "zip_name=%%~nf"
    goto :found
)

:found
rem Remove _Q1 from the zip name
set "zip_name=%zip_name:_Q1=%"
set "zip_name=%zip_name%.zip"

rem Create the zip file containing all .cpp files
powershell -Command "Compress-Archive -Path *.cpp -DestinationPath %zip_name%"

popd
echo Zip file created: %folder%\%zip_name%
