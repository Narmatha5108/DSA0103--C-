# Task 2 — Tokens, keywords, identifiers and constants

Examples from the program:
- Keywords: `enum`, `class`, `return`, `switch`, `case`, `constexpr`.
- Identifiers: `Zone`, `baseFare`, `INNER_FARE_PAISE`.
- Constants: `1000`, `2000`, `3000`, `20`, `5000`.
- Operators: `=`, `<<`, `return`.
- Punctuators: `{}`, `()`, `;`, `,`.

`constexpr` is useful for values known at compile time and has type checking. `#define` is textual substitution and does not provide normal scope/type checking. `enum class` prevents accidental mixing of zone values with unrelated integers. Use uppercase names for constants and descriptive camelCase names for functions.

Complexity: base fare lookup is O(1) time. The constants require no meaningful per-journey storage. Replacing macros with constexpr does not change asymptotic running time.
