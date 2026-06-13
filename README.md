# 42 Exam Rank 05 - Complete Solutions

This repository contains my full set of solutions for **42 Exam Rank 05**, organized by level and exercise.

## Repository Structure

```text
src/
  Level_1/
    bigInt/
    Vect2/
    Polyset/
  Level_2/
    BSQ/
    Game_Of_Life/
```

Each exercise folder includes:
- a `subject/subject.txt` with the original statement,
- the source files,
- a `Makefile`,
- and (for some exercises) a local `main/` used for validation.

## Requirements

- `gcc` / `g++`
- `make`
- Unix-like environment recommended (Linux/macOS or WSL/MSYS2 on Windows)

> Note: on pure Windows PowerShell without a Unix toolchain, `make` may not be available.

---

## Level 1

### 1) bigInt

**Goal**
- Implement a `bigint` class (arbitrary precision unsigned integer).
- Support canonical form, addition, comparisons, and base-10 digit shifts.

**Key points implemented**
- Number stored as `std::string`.
- `+`, `+=`, comparison operators, pre/post increment.
- `<<`, `>>`, `<<=`, `>>=` for digit shifting.

**Path**
- `src/Level_1/bigInt/`

**Build & run**

```bash
cd src/Level_1/bigInt
make
./bigInt
```

---

### 2) Vect2

**Goal**
- Implement a 2D integer vector class with operator overloading.

**Key points implemented**
- Canonical form.
- Arithmetic operators (`+`, `-`, `*`) and compound assignments.
- Scalar multiplication in both forms (`v * n` and `n * v`).
- `[]`, unary `-`, increment/decrement, equality/inequality.

**Path**
- `src/Level_1/Vect2/`

**Build & run**

```bash
cd src/Level_1/Vect2
make
./vect2
```

---

### 3) Polyset

**Goal**
- Extend provided bag abstractions with searchable variants.
- Implement a `set` wrapper that enforces unique values.

**Key points implemented**
- `searchable_array_bag` with linear search.
- `searchable_tree_bag` with BST-style search.
- `set` that inserts only if element is absent.

**Path**
- `src/Level_1/Polyset/`

**Build & run**

```bash
cd src/Level_1/Polyset
make
./polyset 1 2 2 3 4
```

---

## Level 2

### 4) BSQ (Biggest Square)

**Goal**
- Given a map with empty/obstacle cells, find and print the largest possible square.

**Key points implemented**
- Map parsing from file or standard input.
- Validation of map format and symbols.
- Dynamic programming solver (`O(rows * cols)`), with output rendering of the best square.
- Proper handling of multiple input maps and `map error` cases.

**Path**
- `src/Level_2/BSQ/`

**Build**

```bash
cd src/Level_2/BSQ
make
```

**Run with files**

```bash
./bsq maps/map1.txt
./bsq maps/map1.txt maps/map2.txt
```

**Run with stdin**

```bash
cat maps/map1.txt | ./bsq
```

---

### 5) Game of Life

**Goal**
- Simulate Conway's Game of Life from a board drawn by movement commands from `stdin`.

**Key points implemented**
- Pen-based board drawing (`w`, `a`, `s`, `d`, `x`).
- Iterative evolution for `n` generations.
- Out-of-bounds treated as dead cells.
- Final board rendering using `O` for alive and space for dead.

**Path**
- `src/Level_2/Game_Of_Life/`

**Build & run**

```bash
cd src/Level_2/Game_Of_Life
make
echo 'dxss' | ./life 3 3 2
```

---

## Useful Make Targets

Inside each exercise directory:

```bash
make        # build
make clean  # remove objects
make fclean # remove objects + binary
make re     # rebuild from scratch
```

## Notes

- All implementations follow the constraints defined in each official subject.
- Local `main` files are for demonstration/testing and can be adapted to your own checks.
