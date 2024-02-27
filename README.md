# C Algorithms

[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-blue.svg)](/CONTRIBUTING.md "Go to contributions doc")
![GitHub Top Language](https://img.shields.io/github/languages/top/LeonWandruschka/C_Algorithms)
![GitHub Code Size in Bytes](https://img.shields.io/github/languages/code-size/LeonWandruschka/C_Algorithms)
[![Docs](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/documentation.yml/badge.svg)](https://github.com/LeonWandruschka/C_Algorithms/actions/workflows/documentation.yml)

This open-source project aims to collect various C algorithms and data structures, making them available to everyone. We welcome contributions from anyone interested in improving or expanding the project.

## Table of Contents

- [C Algorithms](#c-algorithms)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
  - [Usage](#usage)
  - [Building the Executable](#building-the-executable)
    - [Using CMake](#using-cmake)
      - [Built without Conan](#built-without-conan)
      - [Built with Conan](#built-with-conan)
  - [IDE Setup](#ide-setup)
  - [Setting Up Dependencies](#setting-up-dependencies)
    - [Installing CMake](#installing-cmake)
      - [All Platforms (Windows, Linux, and macOS)](#all-platforms-windows-linux-and-macos)
      - [Quick Install on Linux/macOS](#quick-install-on-linuxmacos)
    - [Installing Conan](#installing-conan)
      - [Linux and Windows](#linux-and-windows)
      - [macOS](#macos)
  - [Project Structure](#project-structure)
  - [Contributing](#contributing)
  - [Authors and Acknowledgment](#authors-and-acknowledgment)
  - [License](#license)
  - [Contact Information](#contact-information)
  - [Future Updates](#future-updates)

## Getting Started

### Prerequisites

- GCC or Clang compiler
- CMake
- Conan (optional for some libraries)

### Installation

To get started with this project:

1. Clone the repository: `git clone https://github.com/LeonWandruschka/C_Algorithms.git`
2. Navigate to the cloned directory and install dependencies (if necessary).

## Usage

After installation, you can build and run specific algorithms as described below. Use `-h` for help on running an algorithm, `x` or `X` to exit the program, or `CTRL+C` for an immediate stop.

## Building the Executable

### Using CMake

You can customize the name of the output folder to suit your needs, moving away from the default `build` name. Moreover, you have the option to create build files for different configurations, specifically for release or debug modes. To achieve this, just append `/debug` or `/release` to the end of your preferred output folder name and adjust the `CMAKE_BUILD_TYPE` accordingly to specify the desired build mode.

#### Built without Conan

> Libraries dependent on a Conan package will not be built, but all other components will proceed to be compiled as expected.

1. Generate build files: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`
2. Build the project: `cmake --build build`

To run the executable after building, use: `cmake --build build --target runExecutable`

For a clean build, add `--clean-first`.

#### Built with Conan

1. Install conan dependencies: `conan install . -sbuild_type=Release -of=build --build=missing`
2. Generate build files: `cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCONAN=ON -DCMAKE_BUILD_TYPE=Release`
3. Build the project: `cmake --build build`

To run the executable after building, use: `cmake --build build --target runExecutable`

For a clean build, add `--clean-first`.

To run the tests you can use `ctest --test-dir ./build/test` from the projects source directory.

## IDE Setup

To use the conan libraries add the include folder to your IDE.
For Linux and macOS the conan install folder should be located at `~/.conan/`.
For Windows users it should be located under `C:\Users\username\.conan\`.

## Setting Up Dependencies

Before starting, ensure that you have either `gcc` or `clang` installed as your C/C++ compiler. This setup guide will also cover the installation of `CMake` for building the project and `Conan` for managing external library dependencies.

### Installing CMake

CMake is crucial for configuring and generating the build files. Follow these steps to install CMake on your system:

#### All Platforms (Windows, Linux, and macOS)

- Download and install CMake from the [official CMake downloads page](https://cmake.org/download/). During the installation, if prompted, remember to add CMake to your system's PATH to make it accessible from the command line.

#### Quick Install on Linux/macOS

For a faster setup on Linux and macOS, you can use the respective package managers:

- **Linux (Debian-based distributions):** `sudo apt update && sudo apt install cmake`

- **macOS (Using Homebrew):** `brew install cmake`

### Installing Conan

Conan simplifies external library management. Below are the instructions for installing Conan on different operating systems.

#### Linux and Windows

1. **Install Python:** Visit the [official Python website](https://www.python.org/downloads/) and follow the instructions to install Python on your system.
2. **Install Conan** With Python installed, open a terminal or command prompt and execute the following command: `pip install conan`
3. **Set Up Conan Profile:** Automatically detect and create a Conan profile by running: `conan profile detect --force`

#### macOS

1. **Install Conan:** If you have Homebrew installed, you can easily install Conan by running:`brew install conan`
2. **Set Up Conan Profile:** Like on Linux and Windows, configure your Conan profile with:

## Project Structure

Here's an overview of the project structure:

``` shell
.
├── CODE_OF_CONDUCT.md
├── CmakeLists.txt
├── Doxyfile
├── LICENSE
├── README.md
├── build
│   ├── release (optional)
│   └── debug   (optional)
├── memory
│   ├── CmakeLists.txt
│   ├── include
│   └── src
├── misc
│   ├── CmakeLists.txt
│   ├── include
│   └── src
├── search
│   ├── CmakeLists.txt
│   ├── include
│   └── src
└── src
    ├── CmakeLists.txt
    └── main.c
```

## Contributing

We welcome contributions! Please see [CONTRIBUTING.md](/CONTRIBUTING.md) for more details on how to contribute to this project.

<!--## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/LeonWandruschka/C_Algorithms/tags).-->

## Authors and Acknowledgment

- **Leon Wandruschka** - *Initial work*

Thanks to all the contributors who participate in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact Information

For any inquiries or contributions, please contact [Leon Wandruschka](https://github.com/LeonWandruschka).

## Future Updates

- Addition of more algorithms and data structures.
- Integration of Conan packages for enhanced functionality.
- Implementation of Catch2 for comprehensive testing.
