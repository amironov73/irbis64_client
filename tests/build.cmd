@echo off

mkdir build     > nul 2> nul
cd build

cmake -A Win32 -D CMAKE_BUILD_TYPE=Release ..
cmake --build .
cmake --build . --target install

cd ..