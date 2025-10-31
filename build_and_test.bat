@echo off
echo Building OOP Lab 2 Project...
echo.

REM Create build directory if it doesn't exist
if not exist build mkdir build
cd build

REM Configure with CMake
echo Configuring with CMake...
cmake ..
if %ERRORLEVEL% neq 0 (
    echo CMake configuration failed!
    pause
    exit /b 1
)

REM Build the project
echo Building project...
cmake --build .
if %ERRORLEVEL% neq 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful!
echo.

REM Run the main program
echo Running main program...
echo ================================
code\OOP_LAB_2.exe
echo ================================
echo.

REM Run unit tests
echo Running unit tests...
echo ================================
tests\unit_tests.exe
echo ================================
echo.

echo All done!
pause

