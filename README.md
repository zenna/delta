#Sigma Machines

### Dependencies
* CMake

### How to build
Make a build directory (preferably outside the source code directory)

	mkdir ~/example/
	cd ~/example/
	cmake REPOSITORY_ROOT
	make

### emcbuild

	mkdir -p ~/builds/infons-emscripten
	cd ~/builds/infons-emscripten
	emcc ~/repos/infons/tests/and.cpp -c -std=gnu++0x  -I ~/repos
	emcc and.o  -o hello.html

	