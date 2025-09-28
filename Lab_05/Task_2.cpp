#include <iostream>

using namespace std;

void functionB(int n);

void printNumbersA(int n) {
    cout << n << " ";
    if (n == 1) {
        cout << endl;
        return;
    }
    printNumbersA(n-1);
}

void functionA(int n) {
    cout << n << " ";
    if (n == 1) {
        cout << endl;
        return;
    }
    functionB(n-1);
}

void functionB(int n) {
    cout << n << " ";
    if (n == 1) {
        cout << endl;
        return;
    }
    functionA(n-1);
}

int main() {
    cout << "printNumbersA" << endl;
    printNumbersA(5);

    cout << endl << "functionA && functionB" << endl;
    printNumbersA(5);
    return 0;
}