#An implementation of the infon model of computation

**infons** 	is a basebones directory structure for getting up and running in a C++ project with cmake support

### Dependencies
* CMake

### Requirements
This library must be able to do the following
* Build (large) networks of infons
* Modify the structure of existing networks:
** Add/remove infons/edges
* Simulate infons
* Find global structures which achieve some desired behaviour
* Do this quickly

Percieved problems
* Data structures for efficient simulation are likely not ones for efficient manipulation
* GPU provides very efficient simulation but likely very inefficient simulation
* 

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

	