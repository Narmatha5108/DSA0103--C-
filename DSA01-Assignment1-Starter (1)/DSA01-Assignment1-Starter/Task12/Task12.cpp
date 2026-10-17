#include <array>
#include <iostream>
#include <string>
using namespace std;

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };
constexpr array<long long, 4> BASE_FARE_PAISE = {1000, 2000, 3000, 6000};
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;

class MonthlyPass {
private:
    Zone first;
    Zone second;
public:
    MonthlyPass(Zone a, Zone b) : first(a), second(b) {}
    bool covers(Zone z) const { return z == first || z == second; }
};

class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}
    long long balance() const { return balancePaise; }
    bool pay(long long farePaise) {
        if (farePaise < 0 || balancePaise - farePaise < MIN_BALANCE_PAISE) return false;
        balancePaise -= farePaise;
        return true;
    }
};

long long calculateFare(Zone zone, int hour, bool weekend, const MonthlyPass& pass) {
    if (pass.covers(zone)) return 0; // Covered zone: pass permits unlimited travel.
    const auto index = static_cast<size_t>(zone);
    long long fare = BASE_FARE_PAISE.at(index);
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);

    // Weekend discount does not combine with the peak surcharge.
    if (weekend) {
        fare -= fare * WEEKEND_DISCOUNT_PERCENT / 100;
    } else if (peak) {
        fare += fare * PEAK_PERCENT / 100;
    }
    return fare;
}

string zoneName(Zone z) {
    switch (z) {
        case Zone::Inner: return "Inner";
        case Zone::Middle: return "Middle";
        case Zone::Outer: return "Outer";
        case Zone::Airport: return "Airport";
    }
    return "Unknown";
}

int main() {
    const MonthlyPass pass(Zone::Inner, Zone::Middle);
    SmartCard card(20000); // Rs 200.00
    struct Journey { Zone zone; int hour; bool weekend; };
    const Journey journeys[] = {
        {Zone::Airport, 9, false},  // weekday peak: Rs 72
        {Zone::Airport, 18, true},  // weekend: 10% discount only => Rs 54
        {Zone::Inner, 12, false},   // pass-covered => Rs 0
        {Zone::Outer, 12, true}     // weekend Outer => Rs 27
    };

    for (const auto& journey : journeys) {
        const long long fare = calculateFare(journey.zone, journey.hour, journey.weekend, pass);
        cout << zoneName(journey.zone) << " fare: Rs " << fare / 100 << '.'
             << (fare % 100 < 10 ? "0" : "") << fare % 100;
        if (card.pay(fare)) {
            cout << " — accepted, balance Rs " << card.balance() / 100 << '.'
                 << (card.balance() % 100 < 10 ? "0" : "") << card.balance() % 100 << '\n';
        } else {
            cout << " — denied (minimum Rs 50 must remain), balance unchanged\n";
        }
    }
}
