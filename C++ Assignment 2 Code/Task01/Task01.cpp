#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
    cout << "Inside call by value: " << fee << '\n';
}
void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}
void applyByPointer(long long* fee, int percent) {
    if (fee) *fee -= *fee * percent / 100;
}

int main() {
    long long fee1 = 45000, fee2 = 45000, fee3 = 45000;
    applyByValue(fee1, 10);
    cout << "Fee after call by value: " << fee1 << '\n';
    applyByReference(fee2, 10);
    cout << "Fee after call by reference: " << fee2 << '\n';
    applyByPointer(&fee3, 10);
    cout << "Fee after call by pointer: " << fee3 << '\n';

    int a = 1, b = 2, c = 3;
    auto change = [](int x, int& y, int* z) {
        x += 10; y += 10; *z += 10;
    };
    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';
    int& bigger = (a > c ? a : c);
    bigger = 100;
    cout << a << ' ' << c << '\n';

    auto show = [](int x, int y = 5, int z = 10) {
        cout << x + y + z << ' ';
    };
    show(1); show(1, 2); show(1, 2, 3);
    cout << '\n';
    return 0;
}
