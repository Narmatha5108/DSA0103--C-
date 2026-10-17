# Task 10 — Expectation vs execution

Run the program and record the exact output from your compiler. For a fixed Rs 30 fare, multiply the number of journeys by 3000 paise using `long long`. The totals are 60,000,000 paise for 20,000 journeys, 1,500,000,000 paise for 500,000 journeys, and 9,000,000,000 paise for 3,000,000 journeys. The last total exceeds the typical 32-bit `int` maximum. Do not actually overflow a signed `int`; signed overflow is undefined behaviour.

A `long long` is suitable for these totals. A `double` can represent large totals but binary fractions such as 0.1 may not be exact. Both additions are O(1) time; the storage size depends on the implementation and is printed by Task03.

Record actual warnings produced by `-Wall -Wextra`; warning messages differ by compiler and source.
