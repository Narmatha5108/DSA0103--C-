#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << boolalpha;
    cout << "sizeof(bool) = " << sizeof(bool) << " byte(s)\n";
    cout << "sizeof(char) = " << sizeof(char) << " byte(s)\n";
    cout << "sizeof(int) = " << sizeof(int) << " byte(s)\n";
    cout << "sizeof(long long) = " << sizeof(long long) << " byte(s)\n";
    cout << "sizeof(float) = " << sizeof(float) << " byte(s)\n";
    cout << "sizeof(double) = " << sizeof(double) << " byte(s)\n";
    cout << "INT_MIN = " << INT_MIN << ", INT_MAX = " << INT_MAX << '\n';

    const long long farePaise = 3000;
    const long long journeys = 3000000;
    const long long totalPaise = farePaise * journeys;
    cout << "Integer-paise total for 3,000,000 journeys at Rs 30: Rs "
         << totalPaise / 100 << '\n';

    double decimalTotal = 0.0;
    for (int i = 0; i < 10; ++i) decimalTotal += 0.1;
    cout << setprecision(17) << "Ten additions of double 0.1 = " << decimalTotal << '\n';
    cout << "Ten additions of integer 10 paise = " << 10 * 10 << " paise\n";
}
