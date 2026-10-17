# Task 6 — Control structures

## Pseudocode
1. Set base fare to zero.
2. Use `switch` on zone to select Rs 10, Rs 20 or Rs 30 in paise.
3. If the journey is during peak hours, add 20% using integer arithmetic.
4. Check whether `balance - fare >= 5000` paise.
5. If allowed, deduct fare; otherwise keep the balance unchanged.
6. Print the fare/denial and balance.

The required completed TODO logic is implemented using `switch` and integer paise. The peak interval is `[08:00, 10:00)` or `[17:00, 20:00)`, so 10:00 and 20:00 are not peak.

## Alternative: fare array
A fare array indexed by zone is O(1) lookup time, just like the switch. The array uses a small fixed amount of storage. Adding a zone requires updating the enum and fare table; a switch also needs another case.
