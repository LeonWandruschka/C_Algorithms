# C Algorithms

[![contributions - welcome](https://img.shields.io/badge/contributions-welcome-blue)](/CONTRIBUTING.md "Go to contributions doc")
![GitHub top language](https://img.shields.io/github/languages/top/LeonWandruschka/C_Algorithms) ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/LeonWandruschka/C_Algorithms) [![Docs](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/documentation.yml/badge.svg)](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/documentation.yml)

This is an open source project to collect various C algorithms and data structures and make them available to everyone.
Everyone is welcome to contribute to the project to make it easier for other developers to search for algorithms.

## Table of Contents

- [Recursive Fibonacci](misc/src/recursiveFib.c) &rarr; Uses a recursive function call to retrun the nth fibonacci number
- [Dynamic Fibonacci](misc/src/dynamicFib.c) &rarr; Uses a for loop to calculate the nth fibonacci number. (Much faster, especially at higher numbers)
- [Pattern Search](search/src/patternSearch.c) &rarr; Search for a specific pattern in a string
- [Stack](memory/src/stack.c) &rarr; Stack like memory (LIFO)
- [Queue](memory/src/queue.c) &rarr; Queue like memory (FIFO)

## Usage

To test one of the librarys download or clone the repository.
In your Terminal or CMD go to the downloaded/cloned folder and use ```cmake``` to create an executable file in the build directory.
The programm will ask you to choose a library to test. Each library has an own character ```a```, ```b```, and so on to see an overview press ```Enter``` or use ```h```/```H```.

### Building the Executable

<!--- Build using Makefile and Cmake --->


Building the Executable using Cmake:

At first run ```cmake -S . -B build``` in the source directory
now run ```cmake --build build --target runExecutable``` to build and run teh executable.
If you only want to build the project you can use just ```cmake --build build```this will build the executable in the ```build/src/``` folder.

To create a clean build use ```cmake --build build --clean-first``` add the target if you want to run the executable file.

## Dependencies

- Understanding of c source code.
- ```gcc``` or ```clang``` must be installed.
- Cmake must be installed
- Conan must be installed for some libraries

## For more information please read the documentation

[![view - Documentation](https://img.shields.io/badge/view-Documentation-blue)](https://leonwandruschka.github.io/C_Algorithms/)

## Future Updates

- Use Cmake as build system.
- Add additional algorithms.
- Add needed conan packages for window display.
- Put Algorithms in specific folders.
- Add Catch2 for testing
