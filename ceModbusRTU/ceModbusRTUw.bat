@REM To run the script set VCPKGDIR environmental variable for vcpkg root folder
if exist ./buildw/ (
rmdir /s /q ./buildw
)
cmake -B ./buildw -S ./ -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=%VCPKGDIR%/scripts/buildsystems/vcpkg.cmake -D CMAKE_INSTALL_PREFIX=./installed/ &&^
cmake --build ./buildw --config Release 
@REM cmake --install ./buildw --config Release
cd buildw/Release
ceModbusRTU.exe
@REM cpack --verbose
cd ../..
