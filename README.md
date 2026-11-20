
# C Memory Mastery

A hands-on journey to mastering the C programming language, with a
particular focus on pointers, memory management, data structures,
and how C works under the hood.

This repository contains practical examples, exercises, experiments,
and progressively more advanced projects.

## Goals

- Understand how C programs use memory.
- Master pointers and pointer arithmetic.
- Understand stack and heap allocation.
- Use malloc, calloc, realloc, and free correctly.
- Understand structs, unions, and enums.
- Master arrays and C strings.
- Learn recursion and dynamic data structures.
- Understand memory ownership and object lifetimes.
- Detect and debug memory errors.
- Build a dynamic object system from scratch.

## Learning Roadmap

| Phase | Topic | Status |
|---|---|---|
| 01 | C Fundamentals | In Progress |
| 02 | Pointers | Planned |
| 03 | Memory Management | Planned |
| 04 | Structs, Unions, and Enums | Planned |
| 05 | Strings and Arrays | Planned |
| 06 | Recursion and Data Structures | Planned |
| 07 | Snek Object System | Planned |
| 08 | Debugging and Advanced C | Planned |

## Requirements

- GCC
- GDB
- Make
- Valgrind
- Git

The examples target C17.

## Compile and Run

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -g \
    path/to/file.c -o program

./program
```

## Debugging

Run a program with GDB:

```bash
gdb ./program
```

Check for memory errors with Valgrind:

```bash
valgrind --leak-check=full --track-origins=yes ./program
```

Use AddressSanitizer when compiling:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -g \
    -fsanitize=address,undefined \
    path/to/file.c -o program
```

## Learning Approach

Every lesson includes:

1. Conceptual explanations.
2. Small C experiments.
3. Practical exercises.
4. Compilation and testing.
5. A descriptive Git commit.

## Progress

This repository is actively developed as I work through each topic.

---

**Language:** C  
**Standard:** C17
