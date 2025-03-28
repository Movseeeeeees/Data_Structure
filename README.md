# Vector Implementation in C++

This project implements a custom `Vector` class in C++ that mimics the behavior of the standard `std::vector` container. It includes features such as dynamic resizing, iterators, and various utility functions.

## Features

- **Dynamic Resizing**: Automatically adjusts capacity as elements are added or removed.
- **Iterators**: Supports forward and reverse iterators.
- **Utility Functions**:
  - `push_back`, `pop_back`
  - `size`, `capacity`, `empty`
  - `reserve`, `shrink_to_fit`, `resize`
  - `clear`, `print`
  - Accessors: `at`, `operator[]`, `front`, `back`

## Usage

### Compilation

To compile the project, use the provided `Makefile`:

```bash
make
```

### Running the Program

After compilation, run the program:

```bash
make run
```

### Cleaning Up

To remove compiled files:

```bash
make clean
```

## Example Output

The program demonstrates the usage of the `Vector` class, including operations like adding, removing, resizing, and iterating over elements. Example output:

```
Hello, World!
size: 0
capacity: 1
empty: 1
size: 3
capacity: 4
empty: 0
1 1 2 
1 1 
size: 3
capacity: 10
empty: 0
size: 4
capacity: 4
empty: 0
size: 5
capacity: 5
empty: 0
1 2 3 4 5 
5 4 3 2 1 
1
1 2 3 4 5 
```

## File Structure

- `src/main.cpp`: Demonstrates the usage of the `Vector` class.
- `src/vector.cpp`: Implementation of the `Vector` class.
- `inc/vector.h`: Declaration of the `Vector` class.
- `Makefile`: Build system for compiling, running, and cleaning the project.

## Requirements

- C++ compiler (e.g., `g++`)
- Make utility

## License

This project is open-source and available under the MIT License.