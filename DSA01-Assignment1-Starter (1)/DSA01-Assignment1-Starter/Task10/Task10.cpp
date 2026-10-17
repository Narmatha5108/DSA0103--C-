#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const long long farePaise = 3000; // Rs 30.00
    const long long sizes[] = {20000, 500000, 3000000};
    cout << "INT_MAX = " << INT_MAX << '\n';

    for (long long n : sizes) {
        const long long totalPaise = n * farePaise;
        const double totalDoubleRupees = static_cast<double>(n) * 30.0;
        cout << "Journeys: " << n
             << ", integer-paise total: " << totalPaise << " paise (Rs "
             << totalPaise / 100 << ")"
             << ", double total: Rs " << fixed << setprecision(2)
             << totalDoubleRupees << '\n';
    }

    cout << "3,000,000 * 3,000 paise = " << 3000000LL * 3000
         << " paise, which is greater than INT_MAX: "
         << boolalpha << (3000000LL * 3000 > INT_MAX) << '\n';

    double repeated = 0.0;
    for (int i = 0; i < 10; ++i) repeated += 0.1;
    cout << setprecision(17) << "Repeated double 0.1 ten times: " << repeated << '\n';
}
