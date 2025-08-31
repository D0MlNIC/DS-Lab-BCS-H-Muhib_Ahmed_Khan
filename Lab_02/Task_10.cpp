#include <iostream>
#include <string>
using namespace std;

int main() {
    int categories;

    cout << "Enter number of book categories: ";
    cin >> categories;

    while(categories<1){
        cout << "Enter a number greater than 0: ";
        cin >> categories;
    }

    string* categoryNames = new string[categories];
    int* bookCounts = new int[categories];
    int** bookIDs = new int*[categories];

    for (int i=0; i<categories; i++) {
        cout << "Enter name for category " << i+1 << ": ";
        cin >> categoryNames[i];

        cout << "Enter number of books in " << categoryNames[i] << ": ";
        cin >> bookCounts[i];

        while(bookCounts[i]<1){
            cout << "Enter number greater than 0: ";
            cin >> bookCounts[i];
        }

        bookIDs[i] = new int[bookCounts[i]];
        for (int j=0; j<bookCounts[i]; j++) {
            cout << "Enter Book ID " << j+1 << " in " << categoryNames[i] << ": ";
            cin >> bookIDs[i][j];
        }
    }

    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    string foundCategory = "";

    for (int i=0; i<categories; i++) {
        for (int j=0; j<bookCounts[i]; j++) {
            if (bookIDs[i][j] == searchID) {
                found = true;
                foundCategory = categoryNames[i];
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "Book ID " << searchID << " is available in category: " << foundCategory << endl;
    } else {
        cout << "Book ID " << searchID << " is not available in the library." << endl;
    }

    for (int i=0; i<categories; i++) {
        delete[] bookIDs[i];
    }
    delete[] bookIDs;
    delete[] categoryNames;
    delete[] bookCounts;

    return 0;
}
