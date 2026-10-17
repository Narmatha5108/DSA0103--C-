#include <iostream>
using namespace std;
constexpr long long MIN_BALANCE_PAISE = 5000;

// Procedural style
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE_PAISE;
}
bool proceduralDeduct(long long& balance, long long fare) {
    if (!proceduralCanTravel(balance, fare)) return false;
    balance -= fare;
    return true;
}

// Object-oriented style
class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}
    long long balance() const { return balancePaise; }
    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise - fare >= MIN_BALANCE_PAISE;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
};

int main() {
    long long proceduralBalance = 10000;
    cout << "Procedural allowed: " << boolalpha
         << proceduralDeduct(proceduralBalance, 2000)
         << ", balance paise: " << proceduralBalance << '\n';

    SmartCard card(10000);
    cout << "OOP allowed: " << card.deduct(2000)
         << ", balance paise: " << card.balance() << '\n';

    cout << "Attempt that would leave less than Rs 50: "
         << card.deduct(3000) << ", balance paise: " << card.balance() << '\n';
}
