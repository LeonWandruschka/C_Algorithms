# C Algorithms

![GitHub top language](https://img.shields.io/github/languages/top/LeonWandruschka/C_Algorithms) ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/LeonWandruschka/C_Algorithms) [![Docs](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/documentation.yml/badge.svg)](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/documentation.yml)

This is an open source project to collect various C algorithms and data structures and make them available to everyone.
Everyone is welcome to contribute to the project to make it easier for other developers to search for algorithms.

## Table of Contents

- [Recursive Fibonacci](src/recursiveFib.c) &rarr; Uses a recursive function call to retrun the nth fibonacci number
- [Dynamic Fibonacci](src/dynamicFib.c) &rarr; Uses a for loop to calculate the nth fibonacci number. (Much faster, especially at higher numbers)
- [Pattern Search](src/patternSearch.c) &rarr; Search for a specific pattern in a string
- [Stack](src/stack.c) &rarr; Stack like memory (LIFO)
- [Queue](src/queue.c) &rarr; Queue like memory (FIFO)
- [Linked List](src/linkedList.c) &rarr; Linked list

## Usage

To test one of the librarys download or clone the repository.
In your Terminal or CMD go to the downloaded/cloned folder and type ```make``` to create an executable file in the build directory.
Now you can start the executable by typing ```./build/main``` or ```./build/mainDebug``` in your Terminal or CMD.
The programm will ask you to choose a library to test. Each library has an own character ```a```, ```b```, and so on to see an overview press ```Enter```.

### Building the Executable

As default the executable file will be build using ```gcc``` and code optimization flags.
To build using ```clang``` or with debugging flags like ```-g``` and diffrent Warnings like ```-Wall, -Wpedantic``` add one or more of the following attributes after ```make```:

| ARGUMENTS | Additional info |
|---|---|
| (Default) DEBUG = 0 | -O3 -std=c17 |
| DEBUG = 1 | -g -O0 -Wall -Wextra -Wpedantic -Wconversion -std=c17 |
| (Default) COMPILER = 0 | gcc |
| COMPILER = 1 | clang |
| (Default) REMOVE_OBJ_FILES = 0 | Removes Objectfiles (.o) from build directory |
| REMOVE_OBJ_FILES = 1 | Creates all Objectfiles (.o) in the build directory |

This could look something like this: ```make DEBUG=0 COMPILER=1```

Remove the curent executable file by using ```make clean``` or only the objectfiles by using ```make cleanobj```.

## Prior requirements

- Understanding of c source code.
- ```gcc``` or ```clang``` must be installed.

## For more information please read the documentation

[Documentation](https://leonwandruschka.github.io/C_Algorithms/)
