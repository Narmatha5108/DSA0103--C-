# Task 5 — Operators and precedence

## Predict before running
Write the five output lines here before executing:
1. __________________
2. __________________
3. __________________
4. __________________
5. __________________

## Concepts to explain
- Multiplication has higher precedence than addition, so `x + y * 2` evaluates multiplication first.
- Parentheses force `(x + y)` to be evaluated first.
- `x++` uses the old value and then increments; `++y` increments first and then uses the new value.
- The conditional operator `?:` chooses one of two values based on a condition.
- `%` gives the remainder. In C++ integer division truncates toward zero, so `-10 / 3` is `-3` and `-10 % 3` is `-1`.
- The `for` loop adds 0, 3, 6 and 9.
- Peak expression: `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. This includes 8:00 and 17:00 but excludes 10:00 and 20:00.
- Avoid `i = i++`; it is not a sound way to increment and may have undefined behaviour depending on the expression/version/context.
