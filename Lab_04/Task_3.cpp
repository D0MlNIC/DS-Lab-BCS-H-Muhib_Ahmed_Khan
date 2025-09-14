#include <iostream>

using namespace std;

void selectionSort(int *nums, int s) {
    int minm = INT_MAX;
    int index = -1;
    for (int i=0; i<s; i++) {
        minm = INT_MAX;
        index = -1;
        for (int j=i; j<s; j++) {
            if (nums[j] < minm) {
                minm = nums[j];
                index = j;
            }
        }
        swap(nums[i], nums[index]);
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

    selectionSort(nums, s);

    cout << "Sorted Array" << endl;
    for (int i=0; i<s; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    delete[] nums;
    return 0;
}