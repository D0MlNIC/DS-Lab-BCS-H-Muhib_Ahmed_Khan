#include <iostream>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    while (departments < 1) {
        cout << "Enter a number greater than 0: ";
        cin >> departments;
    }

    int* empCount = new int[departments];
    double** salaries = new double*[departments];

    for (int i=0; i<departments; i++) {
        cout << "Enter number of employees in department " << i+1 << ": ";
        cin >> empCount[i];

        while (empCount[i]<1) {
            cout << "Enter a number greater than 0: ";
            cin >> empCount[i];
        }

        salaries[i] = new double[empCount[i]];

        for (int j=0; j<empCount[i]; j++) {
            cout << "Enter salary of employee " << j+1 << " in department " << i+1 << ": ";
            cin >> salaries[i][j];
        }
    }

    cout << "Highest salary in each department:" << endl;
    for (int i=0; i<departments; i++) {
        double maxSalary = salaries[i][0];
        for (int j=1; j<empCount[i]; j++) {
            if (salaries[i][j] > maxSalary) {
                maxSalary = salaries[i][j];
            }
        }
        cout << "Department " << i+1 << ": " << maxSalary << endl;
    }

    int maxDeptIndex = 0;
    double maxAvg = 0;

    for (int i=0; i<departments; i++) {
        double sum = 0;
        for (int j=0; j<empCount[i]; j++) {
            sum += salaries[i][j];
        }
        double avg = sum / empCount[i];
        if (i==0 || avg > maxAvg) {
            maxAvg = avg;
            maxDeptIndex = i;
        }
    }

    cout << "Department with highest average salary: Department " << maxDeptIndex + 1 << " with average " << maxAvg << endl;

    for (int i=0; i<departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;

    return 0;
}