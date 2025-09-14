#include <iostream>

using namespace std;

void bubbleSort(int *nums, int s) {
    bool swapp = false;
    for (int i=0; i<s; i++) {
        swapp = false;
        for (int j=i+1; j<s; j++) {
            if (nums[j] < nums[i]) {
                swap(nums[j], nums[i]);
                swapp = true;
            }
        }
        if (swapp == false) {
            break;
        }
    }
}

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

    cout << "Unsorted Array" << endl;
    for (int i=0; i<s; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    bubbleSort(nums, s);

    cout << "Sorted Array" << endl;
    for (int i=0; i<s; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    delete[] nums;
    return 0;
}