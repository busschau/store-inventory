# Store Inventory (C++)

A console-based inventory manager that stores products in a **Binary Search Tree (BST)**.  
Built for my Data Structures course to practice clean code, modular design, and algorithmic thinking under real constraints.

## Features
- Add, update, delete, and search products
- In-memory storage using a BST (ordered insert/search)
- Simple CLI for quick operations

## Data Structure & Complexity
- **BST search/insert/delete**: average **O(log n)**, worst-case **O(n)** (if unbalanced)
- Chosen for ordered traversal and predictable lookups

## Build & Run
```bash
# Build (adjust filenames if needed)
g++ -Wall -g -O2 -o store client.cpp product.cpp table.cpp

# Run (macOS/Linux)
./store

# Run (Windows, MinGW)
store.exe
