# Task 11 — Final recommendation

Recommend integer paise for all money, `long long` for balances and network totals, `enum class` for zones, `constexpr` for compile-time fare constants, and a `SmartCard` class with a private balance. The peak-hour check should be the half-open intervals `[8,10)` and `[17,20)`. Use automated tests for boundaries and invalid inputs.

A compiled-in fare table is simple and fast, but each fare change requires rebuilding/redeploying the program. A configuration file can be read once at startup: reading z fares takes O(z) startup time and O(z) storage, but revisions can be made without recompiling. Validate configuration contents before using them. Limitations include the need to define concession rates and business rules clearly, and to decide how fare changes are versioned.

Base this recommendation on your own actual test results after executing the programs; do not invent measurements.
