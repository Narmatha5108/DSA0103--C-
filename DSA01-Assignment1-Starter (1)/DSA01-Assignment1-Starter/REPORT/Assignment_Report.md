# Assignment 1 Report
## Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System

**Name:** REPLACE WITH YOUR NAME  
**Register Number:** REPLACE WITH YOUR REGISTER NUMBER  
**Course:** DSA01  
**Compiler/version:** Fill in from `g++ --version`  
**GitHub repository:** Paste your repository URL here

## Objective
To design, implement and validate C++ fare logic for a metro smart-card system using suitable data types, constants, operators, control structures and object-oriented programming.

## Task 1 — Object-oriented analysis
Refer to `Task01/Task01_Notes.md`. Insert a UML class diagram here and record the actual Task01 output.

## Task 2 — Tokens and constants
Refer to `Task02/Task02_Notes.md`. Record the actual output and explain the chosen constants.

## Task 3 — Data types and compatibility
Refer to `Task03/Task03_Notes.md`. Copy actual `sizeof`, limits and floating-point experiment results from your run.

## Task 4 — Implicit conversions
**Prediction written before execution:** Fill this section before running Task04.  
**Actual output:** Paste the real output.  
**Explanation:** Refer to `Task04/Task04_Notes.md`.

## Task 5 — Operators and precedence
**Prediction written before execution:** Fill this section before running Task05.  
**Actual output:** Paste the real output and explain each line.

## Task 6 — Control structures
Pseudocode and completed program are in `Task06/`. Add your real output screenshot and discuss the 10:00 and 20:00 boundaries.

## Task 7 — Procedural vs OOP
Refer to `Task07/Task07_Notes.md`. Insert actual output and compare maintainability.

## Task 8 — Input and output
Run valid and invalid input examples. Insert screenshots and explain error recovery.

## Task 9 — Implementation and testing
Fill the following table with the actual results after execution.

| Test | Expected | Actual | Pass/Fail |
|---|---|---|---|
| Inner off-peak | Rs 10 | Fill after run | Fill |
| Middle peak | Rs 24 | Fill after run | Fill |
| Outer peak | Rs 36 | Fill after run | Fill |
| 08:00 boundary | Peak | Fill after run | Fill |
| 10:00 boundary | Off-peak | Fill after run | Fill |
| 17:00 boundary | Peak | Fill after run | Fill |
| 20:00 boundary | Off-peak | Fill after run | Fill |
| Remaining balance exactly Rs 50 | Allowed | Fill after run | Fill |

## Task 10 — Expectation vs execution
Record the actual totals and compiler warnings. Theoretical paise totals for a constant Rs 30 fare:
- 20,000 journeys: 60,000,000 paise = Rs 600,000.
- 500,000 journeys: 1,500,000,000 paise = Rs 15,000,000.
- 3,000,000 journeys: 9,000,000,000 paise = Rs 90,000,000.
The last paise total exceeds the usual 32-bit signed int maximum. Explain why `long long` is suitable.

## Task 11 — Final recommendation
Refer to `Task11/Task11_Notes.md`. Support the recommendation using your actual experiments.

## Task 12 — Design challenge
Refer to `Task12/Task12_Notes.md`. Record the actual program output and defend the interpretation of weekend discount and monthly passes.

## Complexity summary
For a single fare calculation, selecting a fare, checking peak time and checking balance are O(1) time. For n journeys, processing all journeys is O(n) time. A fixed-size fare table is O(1) space; storing t test cases requires O(t) space.

## Conclusion
Write a conclusion only after executing and validating all programs. Mention any issues found and corrected.

## Evidence checklist
- [ ] All 12 programs compiled and executed.
- [ ] Real output screenshots saved in the matching `outputs/` folders.
- [ ] Actual results entered in this report.
- [ ] Compiler version and exact compile command recorded.
- [ ] Name, register number and repository URL filled in.
- [ ] Each task committed separately to GitHub.
