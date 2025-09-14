#include <iostream>

using namespace std;

pair<int, int> combSort(int *nums, int s) {
    float shrink = 1.3;
    int gap = s;
    bool swapp = true;

    int countSwap = 0, countCheck = 0;

    while (gap > 1 || swapp) {
        gap /= shrink;
        if (gap < 1) gap = 1;

        swapp = false;
        for (int i=0; i + gap < s; i++) {
            if (nums[i] > nums[i + gap]) {
                swap(nums[i], nums[i + gap]);
                countSwap++;
                swapp = true;
            }
            countCheck++;
        }
    }

    return {countCheck, countSwap};
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

    pair<int, int> checks = combSort(nums, s);

    cout << "Sorted Array" << endl;
    for (int i=0; i<s; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Conditions Count = " << checks.first << endl;
    cout << "Swaps Count = " << checks.second << endl;

    delete[] nums;
    return 0;
}