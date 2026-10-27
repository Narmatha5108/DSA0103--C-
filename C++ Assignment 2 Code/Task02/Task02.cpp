#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}
const int& highestMarkConst(const int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}
int highestMarkCopy(const int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}

// Demonstrates the compiler warning only. Never call this function:
// its returned reference dangles after the local variable is destroyed.
int& danglingReference() {
    int local = 42;
    return local;
}

int main() {
    int marks[] = {78, 91, 84, 88, 95};
    const int size = sizeof(marks) / sizeof(marks[0]);

    cout << "Highest before moderation: " << highestMarkCopy(marks, size) << '\n';
    highestMark(marks, size) += 2;
    cout << "Highest after +2: " << highestMarkCopy(marks, size) << '\n';
    cout << "Read-only highest: " << highestMarkConst(marks, size) << '\n';

    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    marks[index] += 2;          // index alternative
    int* ptr = &marks[index];
    *ptr += 2;                  // pointer alternative
    cout << "After index and pointer updates: "
         << highestMarkCopy(marks, size) << '\n';
    return 0;
}
