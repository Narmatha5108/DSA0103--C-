# Task 1 — Understand the problem and identify objects

## Objects, data and behaviour
- **SmartCard:** stores balance; checks whether a journey is allowed; deducts a fare safely.
- **Passenger:** can store passenger category such as regular, student or senior citizen.
- **Journey:** stores zone, start time and whether it is a peak-hour journey.
- **Zone:** identifies Inner, Middle or Outer.
- **FareTable:** stores the base fares and returns a fare for a zone.

## OOP principles
- Encapsulation: SmartCard keeps its balance private.
- Abstraction: the caller uses `deduct()` without managing balance arithmetic itself.
- Inheritance: StudentPassenger and SeniorPassenger could derive from Passenger if they need different concession rules.
- Polymorphism: a virtual `concessionPercent()` function could return different concession rates.

## Rules and assumptions
- Store money in integer paise to avoid fractional-paise rounding.
- A journey is allowed only if the remaining balance is at least Rs 50.
- The assignment does not specify the concession percentage; confirm it with the faculty before finalizing.

## Procedural alternative and complexity
A procedural version would use a balance variable and free functions such as `canTravel()` and `deductFare()`. Both designs take O(1) time per journey and O(1) extra space per card. OOP groups state and rules together and reduces the chance of code changing the balance incorrectly.
