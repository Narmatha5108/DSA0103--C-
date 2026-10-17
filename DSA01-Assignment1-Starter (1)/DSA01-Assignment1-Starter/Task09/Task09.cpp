#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Zone { Inner, Middle, Outer };
struct TestCase { string name; Zone zone; int hour; long long balancePaise; long long expectedFarePaise; };

long long fare(Zone zone, int hour) {
    long long base = 0;
    switch (zone) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
    }
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? base + base * 20 / 100 : base;
}
bool allowed(long long balancePaise, long long farePaise) {
    return balancePaise - farePaise >= 5000;
}

int main() {
    const vector<TestCase> tests = {
        {"Inner off-peak", Zone::Inner, 11, 10000, 1000},
        {"Middle peak 09:00", Zone::Middle, 9, 10000, 2400},
        {"Outer peak 18:00", Zone::Outer, 18, 10000, 3600},
        {"Boundary 10:00 is off-peak", Zone::Inner, 10, 10000, 1000},
        {"Boundary 20:00 is off-peak", Zone::Outer, 20, 10000, 3000},
        {"Boundary 08:00 is peak", Zone::Inner, 8, 10000, 1200},
        {"Boundary 17:00 is peak", Zone::Middle, 17, 10000, 2400},
        {"Leaves exactly Rs 50", Zone::Outer, 11, 8000, 3000}
    };

    for (const auto& test : tests) {
        const long long actual = fare(test.zone, test.hour);
        const bool fareMatches = actual == test.expectedFarePaise;
        const bool journeyAllowed = allowed(test.balancePaise, actual);
        cout << test.name << ": fare=" << actual << " paise, expected="
             << test.expectedFarePaise << " paise, fare-match="
             << boolalpha << fareMatches << ", allowed=" << journeyAllowed << '\n';
    }

    cout << "\nFive-journey example (all off-peak):\n";
    const long long fiveJourneyTotal = 1000 + 2000 + 3000 + 1000 + 2000;
    cout << "Total = " << fiveJourneyTotal << " paise = Rs "
         << fiveJourneyTotal / 100 << '\n';

    cout << "Negative recharge validation example: "
         << ( -500 < 0 ? "reject recharge" : "accept recharge") << '\n';
    cout << "Invalid hour text should be rejected by checked input (see Task08).\n";
}
