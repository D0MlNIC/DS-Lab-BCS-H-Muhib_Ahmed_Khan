#include <iostream>

using namespace std;

int interpolationSearch(int *nums, int s, int num) {
    int low = 0, high = s-1, pos;
    while (low <= high && num >= nums[low] && num <= nums[high]) {
        if (low == high) {
            if (nums[low] == num) return low;
            else return -1;
        }

        pos = low + ((num - nums[low]) * (high - low)) / (nums[high] - nums[low]);

        if (nums[pos] == num) return pos;
        if (nums[pos] < num) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
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

    int num;
    cout << "Enter element to search: ";
    cin >> num;

    int index = interpolationSearch(nums, s, num);

    if (index != -1) {
        cout << "Element Found at Index " << index << endl;
    } else {
        cout << "Element Not Found" << endl;
    }

    delete[] nums;
    return 0;
}