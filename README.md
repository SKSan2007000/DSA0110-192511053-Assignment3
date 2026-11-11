# DSA01-192511053-Assignment3

**Name:** B. Santhosh Kumar  
**Register Number:** 192511053  
**Course:** DSA0110 - Object-Oriented Programming with C++  
**Assignment:** 3 (CO3)  
**GitHub Repository:** https://github.com/SKSan2007000/DSA01-192511053-Assignment3

## Compiler
`g++ (Ubuntu)`, C++17.

Standard compile command:
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o run
```

For each task:
```bash
cd TaskNN
g++ -std=c++17 -Wall -Wextra main.cpp -o run
./run
```

## Folder layout
Each task folder contains:
- `main.cpp` - C++ source code
- `sample_output.txt` - output captured from the compiled program
- `notes.md` - purpose, design, complexity and run instructions
- `evidence/compile_output.txt` - compiler command and result
- `evidence/01_compile_and_run.png` - terminal-style capture made from the actual compile/run output

## Task status
| Folder | Question | Status |
|---|---|---|
| Task01 | Constructors and Constructor Overloading | Implemented and compiled |
| Task02 | Copy Constructors: Shallow and Deep Copies | Implemented and compiled |
| Task03 | Dynamic Constructors and Destructors | Implemented and compiled |
| Task04 | Overloading Arithmetic and Stream Operators | Implemented and compiled |
| Task05 | Increment, Comparison and Subscript Operators | Implemented and compiled |
| Task06 | Rules of Operator Overloading | Implemented and compiled |
| Task07 | Complex-Number Class for AC Impedance | Implemented and compiled |

## Report
`REPORT.md` contains the cover-page details, design answers, predictions, explanations, complexity comparisons and engineering decisions.

## Progressive Git commits
The assignment asks for at least one commit per task. After creating the GitHub repository, commit each folder separately. The included `commit_task.sh` is a helper; it does not create a GitHub repository or push without your credentials.

## Important
The execution evidence was produced in this build environment. Re-run the programs on the machine used for submission if your faculty expects screenshots captured directly from your own terminal. Timings are machine-dependent and should be measured on that machine.

## Environment note
The normal C++17 `-Wall -Wextra` builds and program runs completed in the build environment. Selected AddressSanitizer binaries were also compiled, but this container could not initialise the ASan shadow-memory runtime. See `evidence/sanitizer_output.txt` in the selected task folders and rerun the ASan command on your own Ubuntu/WSL machine before submission. Benchmark timings are machine-dependent.
