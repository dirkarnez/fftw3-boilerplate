REM run as Administrator
@echo off

cd /d %~dp0
set DOWNLOADS_DIR=%USERPROFILE%\Downloads
set DOWNLOADS_DIR_LINUX=%DOWNLOADS_DIR:\=/%

SET PATH=^
%DOWNLOADS_DIR%\PortableGit\bin;^
%DOWNLOADS_DIR%\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64;^
%DOWNLOADS_DIR%\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin;^
%DOWNLOADS_DIR%\cmake-3.29.3-windows-x86_64\bin;^

@REM set PATH=^
@REM D:\Softwares\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64;^
@REM D:\Softwares\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin;^
@REM D:\Softwares\cmake-3.23.0-rc1-windows-x86_64\bin;

cmake.exe -G"MinGW Makefiles" ^
-DFFTW3_DIR="%DOWNLOADS_DIR_LINUX%/fftw3-v3.3.10-x86_64-posix-seh-rev0-8.1.0/lib/cmake/fftw3" ^
-DCMAKE_BUILD_TYPE=Debug ^
-B./cmake-build &&^
cd cmake-build &&^
cmake --build . &&^
echo "Successful build" &&^
pause