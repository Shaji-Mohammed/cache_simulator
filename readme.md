# Cache Simulator

## Overview

This project is a cache simulator written in C, developed as part of the CSCI-2122 course. The purpose of this assignment is to practice coding in C and to reinforce the concepts discussed in class on pointers, caching, and the memory hierarchy.

## Objectives

- Implement a cache simulator that uses a limited amount of fast memory.
- Understand and apply concepts of memory hierarchy, including cache sets, lines, and blocks.
- Develop efficient and effective code that follows given specifications.

## Features

- Support for direct-mapped, fully associative, and set-associative caches.
- Simulation of cache hits and misses.
- Calculation and display of hit/miss count and hit-rate.

## Repository Structure

```
├── cache.c
├── cache.h
├── main.c
├── Makefile
└── tests
  ├── test01
  ├── test02
  └── ...
└── readme.md
```

- `cachex/`: Contains the source code and test cases for the cache simulator.
- `cache.c`: Implement your cache simulation logic here.
- `cache.h`: Header file with cache-related declarations.
- `main.c`: Main file to run the cache simulator.
- `Makefile`: Build instructions for the project.
- `tests/`: Directory containing test cases to validate your implementation.

## Installation and Setup

1. Clone the repository:

    ```bash
    git clone https://git.cs.dal.ca/courses/2024-winter/csci-2122/assignment-5/????.git
    ```

2. Navigate to the `cachex` directory:

    ```bash
    cd cachex
    ```

3. Set up a CLion project for this directory or use your preferred IDE.

4. Build the project using the provided `Makefile`:

    ```bash
    make
    ```

## Usage

To run the cache simulator, execute the compiled binary with the necessary input. The input consists of:

1. System configuration: fast memory size and main memory size.
2. Reference stream: number of references followed by the memory addresses.
3. Optional `stats` command to display hit/miss count and hit-rate.

Example input:

```
1024 65536
9
22
48
70
4118
22
4118
2070
4118
22
stats
```

Example output:

```
Loaded value [0xb9cb17b29e5109d2] @ address 0x00000016
Loaded value [0x0394fee63984c8dc] @ address 0x00000030
...
Cache hits: 4, misses: 5
```

## Testing

Run the provided test scripts to validate your implementation:

- Run all tests:

    ```bash
    ./runtests.sh
    ```

- Run a specific test (e.g., test 07):

    ```bash
    ./runtests.sh 07
    ```

