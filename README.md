# lru_cache

A C implementation of a least-recently-used (LRU) cache. The project combines a hash table and a doubly linked list to achieve efficient lookup and eviction behavior in a small, self-contained systems design.

## Overview

An LRU cache evicts the least-recently-used item when the cache is full. The project implements this standard behavior in C using:

- a hash table for fast lookups
- a doubly linked list for recency tracking
- custom utility logic for error handling and cache operations

This is a standard design pattern for data structures and cache behavior, and it is a useful project for demonstrating algorithmic thinking and implementation discipline.

## Features

The current implementation includes:

- key-value cache operations
- insertion with overwrite semantics
- lookup by key
- eviction of the least-recently-used element
- cache printing for debugging
- log generation support
- interactive command-line test interface

## Technical implementation

The core of the project is the relationship between the hash table and the linked list:

- the hash table supports fast lookup through linear probing
- the list tracks recency order for eviction
- the cache API updates the list on access and mutation
- the data structures work together to enforce the LRU policy

Relevant source files include:

- `src/main.c` — interactive test interface
- `src/HashTable.c` — hash table implementation
- `src/double_linked_list.c` — linked-list logic
- `src/lru_usage.c` — LRU cache behavior
- `include/` — project headers

## Repository structure

- `src/` — implementation files
- `include/` — headers
- `Makefile` — build automation
- `README.md` — project documentation

## Prerequisites

- Linux, macOS, or other Unix-like system
- GCC or Clang
- Make

## Build

From the repository root:

```bash
make
```

This generates a runnable binary in `bin/main`.

## Usage

Run the application:

```bash
./bin/main
```

The menu supports:

- `1` — PUT
- `2` — GET
- `3` — PRINT CACHE
- `4` — MAKE LOG
- `99` — EXIT

Example flow:

```text
1
Key: 10
Value: 42
2
Key: 10
GET key=10 -> value=42
```

## Known limitations

- the project is best described as a learning prototype
- there are no formal automated tests
- the README is minimal and the project needs stronger public-facing documentation
- the interface is more of a CLI exercise than a polished library API

## Future improvements

Possible next steps:

- add formal tests
- improve API structure and examples
- add benchmark or stress checks
- increase documentation and clarity
- add explicit performance analysis

## License

This repository includes a license file. Verify the repository metadata before relying on it as a legal statement.

## Related concepts

- data structures
- algorithms
- cache design
- hash tables
- memory locality
- interview preparation
