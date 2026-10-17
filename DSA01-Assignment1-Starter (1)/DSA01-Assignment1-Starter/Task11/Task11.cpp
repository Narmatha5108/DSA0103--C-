#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long FARES_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long fareFor(Zone zone, int hour) {
    const int index = static_cast<int>(zone);
    if (index < 0 || index > 2) return -1;
    long long fare = FARES_PAISE[index];
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    if (peak) fare += fare * PEAK_PERCENT / 100;
    return fare;
}

int main() {
    const long long startingBalance = 10000;
    const long long fare = fareFor(Zone::Outer, 18);
    cout << "Outer peak fare: " << fare << " paise\n";
    cout << "Journey allowed from Rs 100 balance: " << boolalpha
         << (startingBalance - fare >= MIN_BALANCE_PAISE) << '\n';
    cout << "Recommended: long long paise, enum class, constexpr fare table, "
            "private SmartCard balance and automated boundary tests.\n";
}
