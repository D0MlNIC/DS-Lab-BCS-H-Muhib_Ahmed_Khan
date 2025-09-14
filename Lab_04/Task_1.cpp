#include <iostream>

using namespace std;

int main() {
    int s = -1;
    
    while (s < 1) {
        cout << "Enter Array Size: ";
        cin >> s;
    }

    int *nums = new int[s];
    for (int i=0; i<s; i++) {
        cout << "Elem " << i + 1 << ": ";
        cin >> nums[i];
    }

    int num;
    cout << "Enter element to search: ";
    cin >> num;

    bool found = false;
    int index = -1;
    for (int i=0; i<s; i++) {
        cout << nums[i] << endl;
        if (nums[i] == num) {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        cout << "Element Found at Index " << index << endl;
    } else {
        cout << "Element Not Found" << endl;
    }

    delete[] nums;
    return 0;
}