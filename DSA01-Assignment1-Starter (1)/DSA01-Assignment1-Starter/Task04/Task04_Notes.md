# Task 4 — Implicit conversions

## Predict before running
Write your prediction here before executing `Task04.cpp`, as required by the assignment:
- Line 1: __________________
- Line 2: __________________
- Line 3: __________________
- Line 4: __________________

## Explain after running
- `a / b` is integer division because both operands are `int`; converting its result to double happens after the division.
- `static_cast<double>(a) / b` performs floating-point division.
- `'A' + 2` promotes the character to an integer before addition, then initializes a `char`.
- `bool flag = 5` converts nonzero integer 5 to `true`.
- Comparing signed `-1` with unsigned `1` converts the signed value to unsigned in the usual arithmetic conversions, so the comparison is surprising. Compile with `-Wall -Wextra` and record the warnings your compiler actually emits.

Safer alternatives include explicit casts where appropriate and brace initialization to reject narrowing conversions, e.g. `int value{3};`. Do not use `int value{3.7};`, because it is ill-formed due to narrowing.
