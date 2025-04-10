# Data Structures Implementation in C++

This project implements custom data structures in C++, including a `Vector` and a `List`. These implementations mimic the behavior of standard C++ containers and include various utility functions.

## Features

### Vector
- **Dynamic Resizing**: Automatically adjusts capacity as elements are added or removed.
- **Iterators**: Supports forward and reverse iterators.
- **Utility Functions**:
  - `push_back`, `pop_back`
  - `size`, `capacity`, `empty`
  - `reserve`, `shrink_to_fit`, `resize`
  - `clear`, `print`
  - Accessors: `at`, `operator[]`, `front`, `back`

### List
- **Doubly Linked List**: Implements a doubly linked list with support for bidirectional traversal.
- **Utility Functions**:
  - `push_back`, `push_front`, `pop_back`, `pop_front`
  - `insert`, `erase`
  - `reverse`, `print`
  - `Merge`, `Splice`
  - Accessors: `front`, `back`
  - Iterators: `begin`, `end`, `rbegin`, `rend`

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

The program demonstrates the usage of the `Vector` and `List` classes, including operations like adding, removing, reversing, merging, and splicing elements. Example output:

```
List size: 5
List: 1 2 3 4 5 
List: 1 2 3 4 
List: 2 3 4 
List: 4 3 2 
List: 4 3 10 2 
List: 4 3 2 
List2 after merge: 7 6 4 3 2 
List2 after splice: 1 4 7 6 4 3 2 
List: 2 3 4 6 7 4 1 
```

## File Structure

- `src/main.cpp`: Demonstrates the usage of the `Vector` and `List` classes.
- `src/vector.cpp`: Implementation of the `Vector` class.
- `src/list.cpp`: Implementation of the `List` class.
- `inc/vector.h`: Declaration of the `Vector` class.
- `inc/list.h`: Declaration of the `List` class.
- `Makefile`: Build system for compiling, running, and cleaning the project.

## Requirements

- C++ compiler (e.g., `g++`)
- Make utility

## License

This project is open-source and available under the MIT License.
