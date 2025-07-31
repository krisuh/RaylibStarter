@ECHO OFF
setlocal

set BUILD_DIR=build
set GENERATOR="Visual Studio 17 2022"
set CONFIG=Debug
if not exist %BUILD_DIR% (
    echo Creating build directory: %BUILD_DIR%
    mkdir %BUILD_DIR%
)

cd %BUILD_DIR%
echo Configuring project with CMake...
cmake -G %GENERATOR% -DCMAKE_BUILD_TYPE=%CONFIG% ..

if errorlevel 1 (
    echo [ERROR] CMake configure failed.
    exit /b 1
)

echo Building project...
cmake --build . --config %CONFIG%

if errorlevel 1 (
    echo [ERROR] Build failed.
    exit /b 1
)
