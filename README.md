# C Algorithms

[![pages-build-deployment](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/pages/pages-build-deployment/badge.svg)](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/pages/pages-build-deployment)

This is an open source project to collect various C algorithms and data structures and make them available to everyone.
Everyone is welcome to contribute to the project to make it easier for other developers to search for algorithms.

## Table of Contents

- recursiveFib.c   ->  Uses a recursive function call to retrun the nth fibonacci number
- dynamicFib.c  ->   Uses a for loop to calculate the nth fibonacci number. (Much faster, especially at higher numbers)
- patternSearch.c -> Search for a specific pattern in a string
- stack.c -> Implemented stack to arrange data (LIFO)

In work:
- queue.c -> Implementing a queue to arrange data (FIFO)
- linkedList.c
- hashTable.c
- binarySearchTree.c

## Usage

To test/use one of the functions go ahead and remove the ```//``` befor the function call in the main.c file.
Build the main.c using ```make``` to create an executable file in the build directory.

As default the executable file will be build using ```gcc``` and code optimization flags.
To build using ```clang``` or debugging flags like ```-g``` and diffrent Warnings like ```-Wall, -Wpedantic``` add the following attributes after ```make```


| ARGUMENTS | Additional info |
|---|---|
| (Default) DEBUG = 0 | -O3 -std=c17 |
| DEBUG = 1 | -g -O0 -Wall -Wextra -Wpedantic -Wconversion -std=c17 | 
| (Default) COMPILER = 0 | gcc | 
| COMPILER = 1 | clang | 
| (Default) REMOVE_OBJ_FILES = 0 | Removes Objectfiles (.o) from build directory |
| REMOVE_OBJ_FILES = 1 | Creates all Objectfiles (.o) in the build directory | 

This could look something like this: ```make DEBUG=0 COMPILER=1```

Use ```./build/main``` to execute the file.

Remove the curent executable file by using ```make clean```

## Prior requirements

- Understanding of c source code.
- ```gcc``` or ```clang``` must be installed.

## For more information please read the documentation

[Documentation](https://leonwandruschka.github.io/C_Algorithms/)
