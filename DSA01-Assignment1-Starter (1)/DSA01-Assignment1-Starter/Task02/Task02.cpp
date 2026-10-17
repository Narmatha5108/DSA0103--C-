#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long baseFare(Zone zone) {
    switch (zone) {
        case Zone::Inner: return INNER_FARE_PAISE;
        case Zone::Middle: return MIDDLE_FARE_PAISE;
        case Zone::Outer: return OUTER_FARE_PAISE;
    }
    return 0;
}

int main() {
    cout << "Inner fare (paise): " << baseFare(Zone::Inner) << '\n';
    cout << "Middle fare (paise): " << baseFare(Zone::Middle) << '\n';
    cout << "Outer fare (paise): " << baseFare(Zone::Outer) << '\n';
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    cout << "Minimum remaining balance (paise): " << MIN_BALANCE_PAISE << '\n';
}
