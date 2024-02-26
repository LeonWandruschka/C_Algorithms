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
  - [Dependencies](#dependencies)
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

## Dependencies

Ensure you have `gcc` or `clang`, and `CMake` installed. `Conan` is required for managing some library dependencies.

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
