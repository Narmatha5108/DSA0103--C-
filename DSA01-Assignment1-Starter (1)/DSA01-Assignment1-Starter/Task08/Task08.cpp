#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int hour = 0;
    long long balanceRupees = 100;
    cout << "Enter journey hour (0-23): ";
    if (!(cin >> hour)) {
        cout << "Invalid hour: please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }
    if (hour < 0 || hour > 23) {
        cout << "Invalid hour: use 0 to 23.\n";
        return 1;
    }
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    cout << "Peak hour: " << boolalpha << peak << '\n';
    cout << "Card balance: Rs " << fixed << setprecision(2)
         << static_cast<double>(balanceRupees) << '\n';
    cout << "Example formatted fare: Rs " << setw(6) << setfill('0') << 10.5 << '\n';
}
