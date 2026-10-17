# Task 12 — Re-evaluate and adapt the design

## A. Impact analysis
- Add `Airport` to `Zone`.
- Add Rs 60 (6000 paise) to the fare table.
- Add a separate weekend discount rule of 10%.
- Add a `MonthlyPass` class storing two covered zones.
- Update zone display and all range checks/arrays.

## B. Original design evaluation
A switch-based design can add an Airport case, but each switch must be updated consistently. A fare table scales more cleanly for additional zones. `SmartCard` can remain responsible for balance validation, while pass eligibility belongs in a separate class.

## C. Adaptation
The code uses a four-entry fare table, a separate weekend rule, and a MonthlyPass. A pass-covered zone has zero fare. Weekend discount takes precedence and is not combined with peak surcharge. This is an explicit interpretation of “does not combine”; confirm with the faculty if they intended a different rule.

## D. Worked examples and defence
- Weekday Airport peak: Rs 60 + 20% = Rs 72.
- Weekend Airport: Rs 60 − 10% = Rs 54; no peak surcharge is added.
- Inner journey covered by the pass: Rs 0.
- Weekend Outer: Rs 30 − 10% = Rs 27.

The stored-value card still requires at least Rs 50 after paying. Starting from Rs 200, the first three journeys leave Rs 74. The fourth journey costs Rs 27, which would leave Rs 47, so it is denied and the balance remains Rs 74. Run the program and record your actual output as evidence.
