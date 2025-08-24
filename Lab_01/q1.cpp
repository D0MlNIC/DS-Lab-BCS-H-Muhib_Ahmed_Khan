#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
        int balance;

    public:
        BankAccount() : balance(100) {}
        BankAccount(int bal) : balance(bal) {}
        BankAccount(BankAccount &acc) {
            balance = acc.balance;
            balance -= 200;
        }

        void printBalance() {
            cout << "Balance = " << balance << endl;
        }
};

int main() {
    BankAccount acc1;
    BankAccount acc2(1000);
    BankAccount acc3 = acc2;

    cout << "Acc 1 ";
    acc1.printBalance();
    cout << "Acc 2 ";
    acc2.printBalance();
    cout << "Acc 3 ";
    acc3.printBalance();

    return 0;
}