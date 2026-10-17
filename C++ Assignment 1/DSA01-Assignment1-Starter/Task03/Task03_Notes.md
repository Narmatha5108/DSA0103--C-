# Task 3 — Data types and compatibility

Use `bool` for yes/no conditions, `char` for a single character, `int` for small counts/hours, `long long` for balances and network totals, and `double` only when floating-point calculations are genuinely required. Use an enum class for zones. Record the sizes printed by your own compiler because sizes are implementation-dependent.

Money should be stored in integer paise. For example, Rs 30 is 3000 paise. A network of 3,000,000 journeys at Rs 30 each totals 9,000,000,000 paise (Rs 90,000,000), which exceeds a typical 32-bit signed int range; use `long long`.

Both a double addition and an integer addition are O(1) time. A `long long` and a `double` are commonly 8 bytes, but use the program output as your machine's evidence. Floating-point values can have binary rounding error.
