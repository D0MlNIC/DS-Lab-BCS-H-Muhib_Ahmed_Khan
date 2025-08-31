#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months to track expenses: ";
    cin >> n;

    while (n<1) {
        cout << "Enter a number > 0: ";
        cin >> n;
    }

    double* expenses = new double[n];
    for (int i=0; i<n; i++) {
        cout << "Enter expense for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "Do you want to add more months? (y/n): ";
    cin >> choice;

    while (tolower(choice) == 'y') {
        int extra;
        cout << "Enter number of extra months: ";
        cin >> extra;

        while (extra < 1) {
            cout << "Enter a number greater than 0: ";
            cin >> extra;
        }

        int newSize = n + extra;
        double* newExpenses = new double[newSize];
        for (int i=0; i<n; i++) newExpenses[i] = expenses[i];
        delete[] expenses;
        expenses = newExpenses;

        for (int i=n; i<newSize; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> expenses[i];
        }
        n = newSize;
        cout << "Do you want to add more months? (y/n): ";
        cin >> choice;
    }

    double total = 0;
    for (int i=0; i<n; i++) total += expenses[i];
    double average = total / n;

    cout << "Total expenses: " << total << endl;
    cout << "Average monthly expense: " << average << endl;

    delete[] expenses;
    return 0;
}