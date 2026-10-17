# Task 8 — Safe input and output

The program checks whether input extraction succeeded. If letters are entered instead of a number, `cin.fail()` is effectively detected by `if (!(cin >> hour))`; `cin.clear()` resets the error state and `cin.ignore()` discards the invalid line. It also checks the valid hour range. `fixed` and `setprecision(2)` display two decimal places; `setw` and `setfill` control field width and padding.

Alternative: `getline()` reads a full line, then `stoi()` inside `try/catch` converts it. Processing a line of length L is O(L) time and O(L) buffer space; direct formatted input is also linear in the characters consumed. `getline` gives more control over validating the entire line.
