#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;
    int nextIndex;

    void record(double amount) {
        transactions[nextIndex] = amount;
        nextIndex = (nextIndex + 1) % 10;
        if (count < 10) ++count;
    }

public:
    SavingsAccount(const string& number, double openingBalance)
        : accountNumber(number), balance(openingBalance), count(0), nextIndex(0) {}

    void deposit(double amount) {
        if (amount <= 0) { cout << "Deposit must be positive.\n"; return; }
        balance += amount;
        record(amount);
    }
    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal.\n"; return;
        }
        balance -= amount;
        record(-amount);
    }
    void miniStatement() const;
};

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nBalance: " << balance
         << "\nRecent transactions (oldest to newest):\n";
    int start = (count == 10) ? nextIndex : 0;
    for (int i = 0; i < count; ++i)
        cout << transactions[(start + i) % 10] << '\n';
}

int main() {
    SavingsAccount account("SA1001", 5000.0);
    account.deposit(500); account.withdraw(200);
    account.deposit(100); account.withdraw(50);
    account.deposit(300); account.withdraw(100);
    account.deposit(250); account.withdraw(75);
    account.deposit(400); account.withdraw(125);
    account.deposit(600); // 11th transaction overwrites the oldest entry
    account.miniStatement();
    return 0;
}
