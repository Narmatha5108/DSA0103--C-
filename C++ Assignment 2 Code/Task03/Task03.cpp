#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express = false;
    bool insured = false;
};

double charge(int weightGrams) {
    return (weightGrams / 1000.0) * 40.0;
}
double charge(double weightKg, bool express = false, bool insured = false) {
    double total = weightKg * 40.0;
    if (express) total += 50.0;
    if (insured) total += 20.0;
    return total;
}
double charge(const Parcel& parcel) {
    return charge(parcel.weightKg, parcel.express, parcel.insured);
}

int main() {
    cout << "charge(2) = " << charge(2) << '\n';
    cout << "charge(2.0f) = " << charge(static_cast<double>(2.0f)) << '\n';
    cout << "charge(2.0) = " << charge(2.0) << '\n';
    cout << "charge(500) = " << charge(500) << '\n';
    cout << "charge(2.0, true) = " << charge(2.0, true) << '\n';
    Parcel p{2.0, true, true};
    cout << "charge(Parcel) = " << charge(p) << '\n';
    return 0;
}
