#include <iostream>
using namespace std;

class SafePointer {
    private:
        int* ptr;
        int size;

    public:
        SafePointer(int s) {
            size = s;
            ptr = new int[size];
            for (int i=0; i<size; i++) ptr[i] = 0;
        }

        void setValue(int index, int value) {
            if (index >= 0 && index < size) {
                ptr[index] = value;
            } else {
                cout << "Index out of bounds" << endl;
            }
        }

        int getValue(int index) {
            if (index >= 0 && index < size) {
                return ptr[index];
            } else {
                cout << "Index out of bounds" << endl;
                return -1;
            }
        }

        void release() {
            delete[] ptr;
            ptr = 0x0;
        }

        ~SafePointer() {
            if (ptr != 0x0) {
                delete[] ptr;
            }
        }
};

int main() {
    int numStudents = 5;
    SafePointer marks(numStudents);

    for (int i=0; i<numStudents; i++) {
        int mark;
        cout << "Enter marks for student " << i+1 << ": ";
        cin >> mark;
        marks.setValue(i, mark);
    }

    cout << "\nMarks of students:\n";
    for (int i=0; i<numStudents; i++) {
        cout << "Student " << i+1 << ": " << marks.getValue(i) << endl;
    }

    marks.release();

    return 0;
}