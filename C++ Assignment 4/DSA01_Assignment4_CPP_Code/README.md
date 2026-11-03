# DSA01 Assignment 4 – CO4: Designing Reusable Class Hierarchies

## Student details
- Name: ______________________
- Register Number: ______________________
- Compiler and version: ______________________

## Folders
- Q1: Payroll class hierarchy
- Q2: University people hierarchy and virtual diamond
- Q3: Constructors, destructors and member classes
- Q4: Virtual functions, virtual destructor and object slicing
- Q5: Object pointers and this pointer
- Q6: Vehicle rental fleet design challenge

## Compile and run
Example:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic Q1/Task01_PayrollHierarchy.cpp -o task1
```
Windows PowerShell:
```powershell
.\task1.exe
```
Use the same command pattern for each source file.

## Task 4 AddressSanitizer experiment
Use:
```bash
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer original.cpp -o original
```
Run the original defective code separately and save the actual output. The ZIP includes repaired examples; do not claim sanitizer output unless you ran the experiment.

## Result notes
- Q1: Common employee data and a virtual pay interface are placed in Staff.
- Q2: Virtual inheritance gives TeachingAssistant one shared Person base.
- Q3: Base/member objects construct before the derived constructor body and destruct in reverse order.
- Q4: Virtual functions enable runtime dispatch; a virtual destructor supports safe base-pointer deletion; value-copying a derived object into a base causes slicing.
- Q5: this points to the current object; returning *this by reference enables chaining.
- Q6: An abstract Vehicle class supports different vehicle types through polymorphism.

## Submission checklist
1. Create repository `DSA01-<RegisterNumber>-Assignment4`.
2. Upload Q1–Q6 and this README.
3. Add real output screenshots to each task folder.
4. Commit progressively, at least one commit per task.
5. Add your actual GitHub URL to the Word report.
6. Fill in your actual compiler version and student details.
