# C++ Module 08 – Templated Containers, Iterators & Algorithms 📚🧠

✅ **Status**: Completed – all mandatory exercises  
🏫 **School**: 42 – C++ Modules (Module 08)  
🏅 **Score**: 100/100

> *Templated containers, iterators, STL algorithms, ranges, and custom iterable abstractions in C++98.*

---

## 📚 Table of Contents

* [Description](#-description)
* [Goals of the Module](#-goals-of-the-module)
* [Important Notes About Module 08](#-important-notes-about-module-08)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – Easy find](#ex00--easy-find)
  * [ex01 – Span](#ex01--span)
  * [ex02 – MutantStack](#ex02--mutantstack)
* [Requirements](#-requirements)
* [Build & Run](#-build--run)
* [Repository Layout](#-repository-layout)
* [Testing Tips](#-testing-tips)
* [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 08 (C++98)**.

This module focuses on using the **STL the right way**.
Unlike earlier C++ modules, here the goal is not to reimplement everything manually, but to **use standard containers and algorithms whenever they are appropriate**.

The module introduces practical work with:

* **template functions and classes**
* **STL containers**
* **iterators**
* **standard algorithms**
* custom abstractions built on top of STL containers

All exercises are written in **C++98** and compiled with strict flags:

```bash
-Wall -Wextra -Werror -std=c++98
```

According to the official subject, Module 08 explicitly expects you to use the STL — especially containers and algorithms — as much as possible where they make sense.

---

## 🎯 Goals of the Module

Concepts covered in this module:

* **Function templates**
* Working with **STL containers** such as `std::vector`, `std::list`, `std::deque`, etc.
* Using **iterators** to traverse containers
* Using `<algorithm>` functions such as `std::find` and `std::sort`
* Understanding **ranges of iterators**
* Designing a class around a standard container
* Extending/adapting STL behavior instead of rewriting it from scratch
* Practicing **Orthodox Canonical Form** where required by the module rules

---

## ⚠️ Important Notes About Module 08

A few key points from the subject:

* This is the first C++ module where using the **STL is allowed and expected**
* You are encouraged to use:

  * **standard containers**
  * **standard algorithms**
  * **iterator-based design**
* Template implementations may be placed directly in header files, or split into `.hpp` + `.tpp` if desired
* `using namespace ...` and `friend` are forbidden unless explicitly allowed by the subject’s general C++ rules
* In C++ modules, **Norminette does not apply**, but code should still remain clear and readable for peer evaluation

---

## 📦 Exercises Overview

### ex00 – Easy find

> A simple generic search utility for integer containers.

**Goal:**
Implement a function template `easyfind` that accepts:

* a container `T`
* an `int` value to search for

The function must find the **first occurrence** of the given integer inside the container.

If the value is not found, the exercise allows you to either:

* throw an exception
* or return an error value of your choice

The subject specifies that you may assume `T` is a **container of integers**, and you do **not** need to handle associative containers.

**What this exercise is really about:**

* Writing a **generic function template**
* Using iterators returned by containers
* Using `std::find` from `<algorithm>`
* Understanding how generic code works with multiple STL containers

**Typical containers to test with:**

* `std::vector<int>`
* `std::list<int>`
* `std::deque<int>`

**Concepts practiced:**

* Template functions
* Iterator pairs: `begin()` / `end()`
* STL algorithm: `std::find`
* Exception handling or error reporting

---

### ex01 – Span

> Store numbers and compute the shortest and longest distance between them.

**Goal:**
Implement a class `Span` that can store up to **N integers**, where `N` is provided to the constructor as an `unsigned int`.

The class must provide:

* `addNumber()` – adds a single number
* `shortestSpan()` – returns the smallest difference between stored numbers
* `longestSpan()` – returns the largest difference between stored numbers

If:

* the container is already full when adding a number
* or there are fewer than 2 stored numbers when computing spans

the class must **throw an exception**.

The subject also explicitly asks for a way to **insert multiple numbers using a range of iterators**, because calling `addNumber()` thousands of times is inconvenient. It additionally recommends testing with **at least 10,000 numbers**.

**What this exercise is really about:**

* Managing a bounded collection of integers
* Using STL containers internally
* Efficiently computing spans
* Working with **iterator ranges**
* Understanding why sorting helps with shortest-span computation

**Typical implementation ideas:**

* Store values in `std::vector<int>`
* Use `std::sort` before computing shortest span
* Compute longest span from `min` and `max`

**Concepts practiced:**

* Encapsulating an STL container in a class
* Range insertion with iterators
* Sorting and numeric comparisons
* Exception-safe boundary checks

---

### ex02 – MutantStack

> A stack… but iterable.

**Goal:**
Create a class `MutantStack` implemented in terms of `std::stack`, but extended with **iterator support**.

The problem is that `std::stack` is a container adapter and does **not** expose iterators directly.
This exercise asks you to “repair” that by making an iterable stack-like type.

Your `MutantStack` must:

* behave like a normal `std::stack`
* expose all standard stack operations
* additionally provide iterators so its contents can be traversed

The subject’s example demonstrates usage like:

* `push()`
* `pop()`
* `top()`
* `size()`
* `begin()`
* `end()`

and then iterating through the structure with an iterator loop.

**What this exercise is really about:**

* Inheriting from or adapting `std::stack`
* Understanding that `std::stack` uses an underlying container
* Exposing the iterator type of that underlying container
* Bridging adapter behavior with iterable container behavior

**Concepts practiced:**

* Template classes
* Container adapters
* Nested typedefs / dependent types
* Iterators from an underlying container
* Reusing STL design instead of reinventing it

---

## 🛠 Requirements

From the official module rules:

* **Compiler**: `c++`
* **Flags**:

  * `-Wall -Wextra -Werror`
  * and code must also compile with `-std=c++98`
* **Standard**: C++98 only
* **Allowed**: Standard Library usage
* **Forbidden**:

  * external libraries
  * C++11 and newer features
  * Boost
  * `*printf()`, `*alloc()`, `free()`
  * `using namespace <ns_name>`
  * `friend` unless explicitly allowed

Also, for C++ modules in general:

* classes from Module 02 onward should follow the **Orthodox Canonical Form**, unless the exercise says otherwise
* headers must be self-sufficient and protected against double inclusion
* function implementations should not be placed in headers **except for templates**

---

## ▶️ Build & Run

Clone the repository and build each exercise separately:

```bash
git clone <this-repo-url>
cd cpp-module-08
```

### ex00 – Easy find

```bash
cd ex00
make
./easyfind
```

### ex01 – Span

```bash
cd ex01
make
./span
```

### ex02 – MutantStack

```bash
cd ex02
make
./mutantstack
```

> Executable names may differ depending on my Makefiles and naming choices.

---

## 📂 Repository Layout

```text
cpp-module-08/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── easyfind.hpp
│   └── easyfind.tpp          # optional, depending on implementation split
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Span.hpp
│   ├── Span.cpp
│   └── ...
│
└── ex02/
    ├── Makefile
    ├── main.cpp
    ├── MutantStack.hpp
    └── MutantStack.tpp       # optional, depending on implementation split
```

The official subject for Module 08 requires these exercise directories and mandatory files:

* `ex00`: `Makefile`, `main.cpp`, `easyfind.{h, hpp}` and optional `easyfind.tpp`
* `ex01`: `Makefile`, `main.cpp`, `Span.{h, hpp}`, `Span.cpp`
* `ex02`: `Makefile`, `main.cpp`, `MutantStack.{h, hpp}` and optional `MutantStack.tpp`

---

## 🔍 Testing Tips

A few useful manual tests for this module:

### ex00

* Search for a value that exists in:

  * `std::vector<int>`
  * `std::list<int>`
  * `std::deque<int>`
* Search for a value that does **not** exist
* Check that your error handling is clear and consistent

### ex01

* Add numbers until capacity is reached
* Try adding **one more** → should throw
* Call `shortestSpan()` and `longestSpan()` with:

  * no numbers
  * one number
  * many numbers
* Test duplicate values → shortest span may become `0`
* Test with **10,000+ values**, as explicitly recommended in the subject
* Test your **range insertion** with iterators from another container

### ex02

* Verify that `MutantStack` behaves like a normal stack:

  * `push`
  * `pop`
  * `top`
  * `size`
* Iterate through its contents using `begin()` / `end()`
* Compare behavior/output with another iterable STL container, like `std::list`, as suggested by the subject example

---

## 🧾 42 Notes

* Module 08 is important because it marks the point where you are expected to stop avoiding the STL and start **using it properly**. The official subject explicitly says that even if an exercise can be solved without standard containers and algorithms, the goal here is precisely to use them wherever appropriate.
* Template code usually needs to be visible at compile time, so it is normal to place implementations in headers or in `.tpp` files included from headers. The subject explicitly allows both approaches.
* C++ modules do not follow the usual C Norminette workflow, but Makefiles should still follow the standard 42 expectations such as `all`, `clean`, `fclean`, and `re`.

---

If you’re a 42 student working on the same module, feel free to explore the repository for inspiration — but make sure to build your own understanding and write your own implementation. That’s the whole point of the C++ modules. 🚀
