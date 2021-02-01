@echo off

mkdir build     > nul 2> nul
cd build

cmake -D CMAKE_BUILD_TYPE=Release ..
cmake --build .

cd ..