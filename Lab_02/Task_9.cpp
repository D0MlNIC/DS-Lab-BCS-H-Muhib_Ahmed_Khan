#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    while(rows<1 || cols<1){
        cout << "Both rows and columns must be greater than 0. Enter again." << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
    }

    int** matrix = new int*[rows];
    for (int i=0; i<rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix in normal form:" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Compressed form (row column value):" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (matrix[i][j]!=0) {
                cout << i << " " << j << " " << matrix[i][j] << endl;
            }
        }
    }

    for (int i=0; i<rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
