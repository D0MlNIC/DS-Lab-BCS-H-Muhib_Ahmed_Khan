#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;

    while(n<1 || m<1){
        cout << "Both values must be greater than 0. Enter again." << endl;
        cout << "Enter number of days: ";
        cin >> n;
        cout << "Enter number of readings per day: ";
        cin >> m;
    }

    double** temps = new double*[n];
    for (int i=0; i<n; i++) {
        temps[i] = new double[m];
    }

    for (int i=0; i<n; i++) {
        cout << "Enter " << m << " temperature readings for day " << i+1 << ":" << endl;
        for (int j=0; j<m; j++) {
            cout << "Reading " << j+1 << ": ";
            cin >> temps[i][j];
        }
    }

    double* averages = new double[n];
    for (int i=0; i<n; i++) {
        double sum = 0;
        for (int j=0; j<m; j++) {
            sum += temps[i][j];
        }
        averages[i] = sum/m;
    }

    cout << "Daily average temperatures:" << endl;
    for (int i=0; i<n; i++) {
        cout << "Day " << i+1 << ": " << averages[i] << endl;
    }

    int hottest=0, coldest=0;
    for (int i=1; i<n; i++) {
        if (averages[i] > averages[hottest]) hottest=i;
        if (averages[i] < averages[coldest]) coldest=i;
    }

    cout << "Hottest day: Day " << hottest+1 << " with average temperature " << averages[hottest] << endl;
    cout << "Coldest day: Day " << coldest+1 << " with average temperature " << averages[coldest] << endl;

    for (int i=0; i<n; i++) {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] averages;

    return 0;
}