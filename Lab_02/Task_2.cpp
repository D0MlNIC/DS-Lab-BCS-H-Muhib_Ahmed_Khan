#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of benches (rows): ";
    cin >> rows;
    while (rows<1) {
        cout << "Enter rows > 0: ";
        cin >> rows;
    }

    cout << "Enter number of seats per bench (columns): ";
    cin >> cols;
    while (cols<1) {
        cout << "Enter columns > 0: ";
        cin >> cols;
    }
\
    int** seats = new int*[rows];
    for (int i=0; i<rows; ++i) {
        seats[i] = new int[cols];
        for (int j=0; j<cols; ++j) {
            seats[i][j] = 0;
        }
    }

    char choice;
    do {
        int r, c;
        cout << "Enter row (0 to " << rows-1 << "): ";
        cin >> r;
        cout << "Enter column (0 to " << cols-1 << "): ";
        cin >> c;

        if (r<0 || r>=rows || c<0 || c>=cols) {
            cout << "Invalid position!" << endl;
        } else {
            seats[r][c] = 1;
            cout << "Seat at [" << r << ", " << c << "] marked as occupied." << endl;
        }

        cout << "Do you want to occupy another seat? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    cout << "Final seating chart:" << endl;
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<rows; ++i) {
        delete[] seats[i];
    }
    delete[] seats;

    return 0;
}