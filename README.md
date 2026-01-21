# LRU Cache Implementation (C++)

This repository contains a high-performance implementation of a **Least Recently Used (LRU) Cache** using **C++**, designed with a strong focus on **correctness, predictable performance, and memory efficiency**.

The cache supports **O(1)** average-time `get` and `set` operations by combining a **hash map** with a **doubly linked list**, a classic and widely used systems design pattern.

---

## 🚀 Key Features

- **O(1) average-time complexity** for both `get` and `set`
- Custom **doubly linked list** with sentinel nodes to maintain recency ordering
- **Hash-based indexing** for fast key lookup
- Correct eviction of the **least recently used** entry upon capacity overflow
- Handles edge cases such as:
  - Capacity boundaries
  - Repeated access
  - Key overwrites
- Explicit memory management with proper cleanup

---

## 🧠 Design Overview

### Data Structures Used
- **`unordered_map<int, Node*>`**
  - Maps cache keys directly to nodes in the linked list
- **Doubly Linked List**
  - Maintains usage order:
    - Front → Most Recently Used (MRU)
    - Back → Least Recently Used (LRU)

### Core Invariants
- Every cache entry exists **exactly once** in both the hash map and the linked list
- Most recently accessed items are always moved to the front
- Least recently used items are evicted first when capacity is reached
- All operations preserve constant-time behavior

---

## 🧩 Algorithm Complexity

| Operation | Time Complexity |
|---------|-----------------|
| `get()` | O(1) average |
| `set()` | O(1) average |
| Space   | O(capacity) |

---

## 🛠️ How to Build & Run

### Compile
```bash
g++ -std=c++17 lru_cache.cpp -o lru_cache
```

###  Run

```bash
./lru_cache
```

###  Example Usage

```bash
LRUCache cache(2);

cache.set(1, 10);
cache.set(2, 20);
cache.get(1);     // returns 10

cache.set(3, 30); // evicts key 2
cache.get(2);     // returns -1
```

### 🎯 Why This Implementation

This implementation emphasizes:

Predictable runtime guarantees

Clear data structure invariants

Low-level systems thinking

Robust handling of edge cases

It is well-suited for technical interviews, systems programming, and high-performance applications.
