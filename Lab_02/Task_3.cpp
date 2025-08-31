#include <iostream>
using namespace std;

int main() {
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;

    while (numStudents < 1) {
        cout << "Enter a number greater than 0: ";
        cin >> numStudents;
    }

    int** marks = new int*[numStudents];
    int* numCourses = new int[numStudents];

    for (int i=0; i<numStudents; i++) {
        cout << "Enter number of courses for student " << i + 1 << ": ";
        cin >> numCourses[i];

        while (numCourses[i] < 1) {
            cout << "Enter courses > 0: ";
            cin >> numCourses[i];
        }

        marks[i] = new int[numCourses[i]];

        for (int j=0; j<numCourses[i]; j++) {
            cout << "Enter mark for course " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << endl << "Average marks per student:" << endl;

    for (int i=0; i<numStudents; i++) {
        int sum = 0;
        for (int j=0; j<numCourses[i]; j++) {
            sum += marks[i][j];
        }
        double average = sum / numCourses[i];
        cout << "Student " << i+1 << ": " << average << endl;
    }

    for (int i=0; i<numStudents; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] numCourses;

    return 0;
}