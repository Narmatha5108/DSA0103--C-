# Task 9 — Implement and test fare logic

The test program covers normal fares, peak fares and the exact boundary hours 08:00, 10:00, 17:00 and 20:00. It also checks a balance that leaves exactly Rs 50. Fares are represented in paise. Unknown-zone and invalid-hour input should be rejected in an interactive version; a negative recharge must be rejected before it changes the card balance.

**Important:** Run the program and copy its actual results into the report. The expected fare for the “leaves exactly Rs 50” case is Rs 30 because the starting balance is Rs 80 and the off-peak Outer fare is Rs 30.

Alternative: storing t test cases in a vector and looping through them takes O(t) time and O(t) storage. Adding a boundary case is easy: add another test record.
