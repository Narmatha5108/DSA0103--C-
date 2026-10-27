#include <iostream>
#include <string>
using namespace std;

class BusTicket {
private:
    static int issued;
    static const int CAPACITY = 3;
    int seat;
    string name;

public:
    explicit BusTicket(const string& passenger) : seat(0), name(passenger) {
        if (issued < CAPACITY) seat = ++issued;
    }
    static int count() { return issued; }
    void print() const {
        if (seat) cout << name << ": Seat " << seat << '\n';
        else cout << name << ": Waiting\n";
    }
};

int BusTicket::issued = 0;

int main() {
    BusTicket trip[4] = {BusTicket("Asha"), BusTicket("Bala"),
                         BusTicket("Chitra"), BusTicket("Dev")};
    for (const BusTicket& ticket : trip) ticket.print();
    cout << "Issued: " << BusTicket::count() << '\n';
    return 0;
}
