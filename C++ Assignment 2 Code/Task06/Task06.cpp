#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return abs(first - second);
}
inline bool earlier(const Time& a, const Time& b) {
    if (a.h != b.h) return a.h < b.h;
    return a.m < b.m;
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time beforeNoon(11, 50), afterNoon(12, 10);
    cout << minutesBetween(beforeNoon, afterNoon) << ' '
         << earlier(beforeNoon, afterNoon) << '\n';

    Time sameA(14, 30), sameB(14, 30);
    cout << minutesBetween(sameA, sameB) << ' '
         << earlier(sameA, sameB) << '\n';
    return 0;
}
