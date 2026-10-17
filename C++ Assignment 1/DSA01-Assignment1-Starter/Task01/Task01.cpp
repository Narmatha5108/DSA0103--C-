#include <iostream>
#include <string>
using namespace std;

class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long initialPaise) : balancePaise(initialPaise) {}
    long long balance() const { return balancePaise; }
    bool canTravel(long long farePaise, long long minimumPaise) const {
        return farePaise >= 0 && balancePaise - farePaise >= minimumPaise;
    }
    bool deduct(long long farePaise, long long minimumPaise) {
        if (!canTravel(farePaise, minimumPaise)) return false;
        balancePaise -= farePaise;
        return true;
    }
};

int main() {
    constexpr long long MIN_BALANCE_PAISE = 5000;
    SmartCard card(10000);
    const long long farePaise = 2000;

    cout << "Initial balance: Rs " << card.balance() / 100 << '\n';
    if (card.deduct(farePaise, MIN_BALANCE_PAISE))
        cout << "Journey allowed. Balance: Rs " << card.balance() / 100 << '\n';
    else
        cout << "Journey denied. Balance: Rs " << card.balance() / 100 << '\n';
}
