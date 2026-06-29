# Viva Voce — Likely Questions & Answers

## 1. Why do we need header files in C++?

**Answer:** Header files contain *declarations* (types, function signatures), while `.cpp` files contain *implementations*. When `main.cpp` uses a function from `admission.cpp`, it only needs to know the function's signature (name, return type, parameters) — not its body. The header provides that contract. The compiler verifies the call matches the declaration; the linker later connects the call to the actual implementation.

## 2. What does `#ifndef` do?

**Answer:** `#ifndef` (if not defined) is an include guard. If the header gets included twice in the same compilation unit (e.g., `file_manager.h` includes `applicant.h`, and `main.cpp` includes both), the guard prevents the compiler from seeing the same declarations twice — which would cause a "redefinition" error.

## 3. Explain `std::vector`. How is it different from a raw array?

**Answer:** `std::vector` is a dynamic array: it grows and shrinks automatically via `push_back()`/`pop_back()`. A raw C array (`int arr[10]`) has a fixed size set at compile time. The vector manages its own memory on the heap, tracks its size (`v.size()`), and cleans itself up when it goes out of scope (RAII). In JavaScript terms, `vector` ≅ `Array` (which is also dynamic).

## 4. Why does `registerApplicant` take `std::vector<Applicant>&` (with `&`)?

**Answer:** The `&` means **pass by reference**. Without it, C++ would *copy* the entire vector into the function — slow and wasteful. With the reference, the function operates on the *original* vector. The function needs to modify it (`push_back`), so we can't use `const`. Compare: in JS, objects are always passed by reference automatically; in C++ you must opt in with `&`.

## 5. What does `const std::string& department` mean?

**Answer:** `const` means the function promises not to modify the string. `&` means pass by reference (no copy). Together: "give me read-only access to this string without copying it." This is the most efficient way to pass strings into functions.

## 6. Explain RAII in the context of file streams.

**Answer:** RAII = Resource Acquisition Is Initialization. When you create a `std::ofstream`, it opens the file. When the stream object goes out of scope (at the end of the function or block), its destructor automatically closes the file. You never need to call `file.close()` explicitly. This prevents resource leaks even if an exception is thrown.

## 7. What's the difference between `#include <iostream>` and `#include "applicant.h"`?

**Answer:** Angle brackets (`<>`) tell the compiler to search system include paths (where the standard library lives). Quotes (`""`) tell it to search the current project directory first, then system paths. Your own headers use quotes; standard library headers use angle brackets.

## 8. Why did we use `std::getline` instead of `std::cin` for names?

**Answer:** `std::cin >> str` stops reading at the first whitespace character. "John Doe" would be read as just "John". `std::getline(cin, str)` reads the entire line including spaces. But after a `std::cin >> choice`, a leftover `\n` sits in the buffer, so `std::cin.ignore()` must be called first to discard it.

## 9. What does `std::stoi` do and how do you handle bad data?

**Answer:** `std::stoi` converts a `std::string` to an `int` (like `parseInt`). If the string isn't a valid number, it throws an exception. In `file_manager.cpp`, we wrap it in a `try/catch(...)` block — if a line in `applicants.txt` is corrupted (e.g., someone manually edited the file), we skip that line with a warning instead of crashing the program.

## 10. How does the score validation loop work?

**Answer:** We use a `while (true)` loop around JAMB score input. If the input is non-numeric (`cin.fail()`) or out of range (0–400), we print an error and `continue` — re-prompting until valid input is received. Only then do we `break` and proceed.

## 11. How does the search function work?

**Answer:** `searchApplicant()` takes a name query from the user, then iterates through the vector using `std::string::find()` to check if the query is a substring of any applicant's name. Matches are collected as pointers (`const Applicant*`) in a separate vector and displayed in a formatted table.

## 12. How does the statistics function work?

**Answer:** It iterates through all applicants and counts totals, admitted, and not-admitted. It uses `std::map<std::string, int>` to track per-department counts — one map for total per department (`deptTotal`), another for admitted per department (`deptAdmitted`). The structured binding (`const auto& [dept, count]`) in the range-for loop unpacks each map entry.

## 13. Why use `std::map` for department statistics?

**Answer:** `std::map` automatically keeps keys sorted and provides O(log n) lookup. When we do `deptTotal[a.department]++`, it either inserts a new entry (initialized to 0, then incremented) or increments an existing one — same pattern as a JS object `obj[key] = (obj[key] || 0) + 1`.

## 14. Explain the `try/catch(...)` in file_manager.cpp.

**Answer:** `try` wraps code that might fail; `catch(...)` catches *any* exception (vs catching a specific type like `std::invalid_argument`). When `std::stoi` receives a non-numeric string, it throws. We catch it, print a warning, and `continue` to the next line — the program stays running.

## 15. Explain the compilation and linking process.

**Answer:**
1. **Preprocessing** — `#include` directives are replaced with actual header content, macros expanded
2. **Compilation** — each `.cpp` file is compiled to an object file (`.o`). The compiler checks types and syntax
3. **Linking** — the linker stitches all `.o` files together, resolves function calls between files, and produces the executable

Command: `g++ -std=c++17 main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit`
This runs all three steps: preprocess → compile → link.
