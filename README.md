#Sigma Machines

### Dependencies
* CMake
* C++11 (suggest latest release clang/llvm from source, or g++--4.6

### How to build
Make a build directory (preferably outside the source code directory)

	mkdir ~/sigmabuild/
	cd ~/sigmabuild/
	cmake REPOSITORY_ROOT -D CMAKE_BUILD_TYPE=Debug -D CMAKE_CXX_COMPILER=clang++
	make