# CampusAdmit — College Admission System

A modular C++17 console application for managing university admissions.

## Quick Start

### Linux / macOS
```bash
g++ -std=c++17 main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit
./CampusAdmit
```

### Windows (MinGW / GCC via MSYS2)
```bash
g++ -std=c++17 main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit.exe
CampusAdmit.exe
```

### Windows (Visual Studio)
```powershell
cl /EHsc /std:c++17 main.cpp applicant.cpp admission.cpp file_manager.cpp /Fe:CampusAdmit.exe
CampusAdmit.exe
```

### macOS (Xcode CLT)
```bash
clang++ -std=c++17 main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit
./CampusAdmit
```

## Project Structure

| File | Purpose |
|---|---|
| `main.cpp` | Entry point, menu loop, user input |
| `applicant.h` | Applicant struct + display declaration |
| `applicant.cpp` | Display applicants table |
| `admission.h` | Cut-off / evaluation declarations |
| `admission.cpp` | Department cut-off logic + status check |
| `file_manager.h` | File save/load declarations |
| `file_manager.cpp` | Read/write applicants.txt |
| `applicants.txt` | Persisted data (auto-created) |

## Features

- **Register** applicants with name, department, and JAMB score
- **Auto-adjudication** — compares score to department cut-off, sets ADMITTED or NOT ADMITTED
- **View** — formatted table of all applicants
- **Save/Load** — automatic persistence to `applicants.txt` on exit, auto-load on start
- **Input validation** — rejects non-numeric scores and menu choices

## Department Cut-offs

| Department | Cut-off |
|---|---|
| Medicine | 270 |
| Computer Science | 250 |
| Law | 250 |
| Accounting | 240 |
| Mass Communication | 220 |
| Business Administration | 200 |
| Any other | 200 |

## File Format (applicants.txt)

```
Name|Department|Score|Status
John Doe|Computer Science|285|ADMITTED
```

## Compilation

```bash
# Debug build with warnings (Linux/macOS)
g++ -std=c++17 -Wall -Wextra main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit

# Release build (optimized)
g++ -std=c++17 -O2 main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit

# Debug build with symbols (for GDB)
g++ -std=c++17 -g main.cpp applicant.cpp admission.cpp file_manager.cpp -o CampusAdmit

# Windows (MSVC)
cl /EHsc /std:c++17 main.cpp applicant.cpp admission.cpp file_manager.cpp /Fe:CampusAdmit.exe
```

## Menu

```
========================
     CampusAdmit
========================
1. Register Applicant
2. View Applicants
3. Search Applicant
4. View Statistics
5. Save Applicants
6. Exit
------------------------
Choice:
```

## Concepts Covered

| C++ Feature | Where Used |
|---|---|
| `struct` | `applicant.h:9` — data grouping |
| `vector` | `main.cpp:75` — dynamic array |
| `string` | `applicant.h:10-13` — text data |
| `map` | `applicant.cpp:114,115` — department statistics |
| `fstream` / `ifstream` / `ofstream` | `file_manager.cpp:9,27` — file I/O |
| `namespace` | Every `.h` file — scope control |
| `#include` guards | Every `.h` file — prevent redefinition |
| `switch` / `while` | `main.cpp:91,81` — control flow |
| `getline` | `main.cpp:36,39` — line input |
| `iomanip` / `setw` | `applicant.cpp:14-35` — table formatting |
| `const &` parameters | `admission.h:8-9` — read-only references |
| `auto` | `file_manager.cpp:16,35` — type inference |
| `try/catch` | `file_manager.cpp:47-51` — corrupted file handling |
| `structured bindings` | `applicant.cpp:141` — `const auto& [dept, count]` |
| `range-based for` | `applicant.cpp:26,76,117` — iterating vector/map |
