# Task 7 — Procedural vs object-oriented

Both versions keep the same rule: the journey is accepted only if the remaining balance is at least 5000 paise. Both have O(1) time per check/deduction and O(1) space per card. The OOP version makes the balance private and exposes only controlled methods. A public balance could be changed directly and could violate the minimum-balance rule. The procedural version can also be safe, but every caller must follow the same functions consistently.
