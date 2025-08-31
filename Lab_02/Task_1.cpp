#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    while (size<1) {
        cout << "Enter size > 1: ";
        cin >> size;
    }

    int* arr = new int[size];

    for (int i=0; i<size; i++) {
        arr[i] = 0;
    }

    char choice;
    do {
        int index, value;
        cout << "Enter index to update from 0 to " << size-1 << ": ";
        cin >> index;

        if (index<0 || index>=size) {
            cout << "Invalid index!" << endl;
        } else {
            cout << "Enter new value please: ";
            cin >> value;
            arr[index] = value;
        }

        cout << "Do you want to update another value? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    cout << endl;
    cout << "Final array: ";
    for (int i=0; i<size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}