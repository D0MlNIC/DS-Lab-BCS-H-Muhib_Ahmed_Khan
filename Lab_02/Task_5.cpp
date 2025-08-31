#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    while (rows < 1 || cols < 1) {
        cout << "Rows and columns must be > 0." << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
    }

    int** mat1 = new int*[rows];
    int** mat2 = new int*[rows];
    int** sum = new int*[rows];
    int** diff = new int*[rows];

    for (int i=0; i<rows; i++) {
        mat1[i] = new int[cols];
        mat2[i] = new int[cols];
        sum[i] = new int[cols];
        diff[i] = new int[cols];
    }

    cout << "Enter elements for Matrix 1:" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements for Matrix 2:" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> mat2[i][j];
        }
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    cout << "Matrix Addition:" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix Subtraction:" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<rows; i++) {
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] sum[i];
        delete[] diff[i];
    }

    delete[] mat1;
    delete[] mat2;
    delete[] sum;
    delete[] diff;

    return 0;
}