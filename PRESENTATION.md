# CampusAdmit — Presentation Talking Points

## Slide 1: Title
- CampusAdmit: College Admission System
- C++17, modular design, STL only

## Slide 2: Problem
- Manual admission processing is error-prone and slow
- Need a system to register applicants, check eligibility, and persist data

## Slide 3: Architecture
- 4 modules: Applicant, Admission, FileManager, Main
- Each module has a `.h` (interface) and `.cpp` (implementation)
- Namespace `CampusAdmit` prevents name collisions

## Slide 4: Applicant Module
- `struct Applicant` — bundles name, score, department, status
- `displayApplicants()` — formatted table output
- Single responsibility: manage applicant data and presentation

## Slide 5: Admission Module
- `getCutOff(department)` → returns cut-off score per department
- `evaluateAdmission(score, dept)` → returns ADMITTED or NOT ADMITTED
- Separation of concerns: admission rules are isolated and easy to modify

## Slide 6: File Manager Module
- `saveApplicants()` — writes `applicants.txt` using `|` delimiter
- `loadApplicants()` — reads and parses the file back into the vector
- Auto-load on startup, auto-save on exit
- RAII: file streams close automatically

## Slide 7: Main Module
- Infinite `while` loop with `switch` for menu
- Three helper functions: `showMenu()`, `clearInputBuffer()`, `registerApplicant()`
- Input validation for both menu choice and score

## Slide 8: C++ Concepts Demonstrated
- `struct` = data grouping
- `vector` = dynamic array
- `fstream` = file I/O
- `#include` guards = prevent double-declaration
- `const &` = read-only reference (no copy)
- `namespace` = scope control

## Slide 9: Demo
1. Register applicants in different departments
2. Show ADMITTED vs NOT ADMITTED
3. Exit and restart — data persists
4. Test invalid input handling

## Slide 10: Testing
- Tested across departments with varying scores
- Edge cases: empty list, boundary scores, invalid input
- File persistence verified across sessions

## Slide 11: Future Improvements
- Edit/delete applicants
- Search and filter by department or status
- GUI (Qt or web frontend)
- Database instead of flat file (SQLite)
- Multi-user with login system
