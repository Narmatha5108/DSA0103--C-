#include <iostream>
using namespace std;

// Baseline design: shifts values after the history becomes full.
class ShiftHistory {
private:
    static const int CAPACITY = 10;
    int values[CAPACITY];
    int count = 0;
public:
    void add(int value) {
        if (count < CAPACITY) values[count++] = value;
        else {
            for (int i = 1; i < CAPACITY; ++i) values[i - 1] = values[i];
            values[CAPACITY - 1] = value;
        }
    }
    void print() const {
        cout << "Shift history: ";
        for (int i = 0; i < count; ++i) cout << values[i] << ' ';
        cout << '\n';
    }
};

// Redesigned: circular buffer inserts in O(1), including when full.
class CircularHistory {
private:
    static const int CAPACITY = 10;
    int values[CAPACITY];
    int count = 0;
    int nextIndex = 0;
public:
    void add(int value) {
        values[nextIndex] = value;
        nextIndex = (nextIndex + 1) % CAPACITY;
        if (count < CAPACITY) ++count;
    }
    void print() const {
        cout << "Circular history: ";
        int start = (count == CAPACITY) ? nextIndex : 0;
        for (int i = 0; i < count; ++i)
            cout << values[(start + i) % CAPACITY] << ' ';
        cout << '\n';
    }
};

int main() {
    ShiftHistory original;
    CircularHistory redesigned;
    for (int value = 1; value <= 15; ++value) {
        original.add(value);
        redesigned.add(value);
    }
    original.print();
    redesigned.print();
    cout << "Both retain the latest 10 values (6 through 15).\n";
    cout << "Shift insertion when full: O(n); circular insertion: O(1).\n";
    return 0;
}
