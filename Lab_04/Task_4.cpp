#include <iostream>

using namespace std;

void insertionSort(int *nums, int s) {
    for (int i=1; i<s; i++) {
        int key = nums[i];
        int j = i-1;
        
        while(j >= 0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = key;
    }
}

int binarySearch(int *nums, int s, int num) {
    int left = 0, right = s-1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == num) {
            return mid;
        } else if (nums[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
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

    
    cout << "Unsorted Array" << endl;
    for (int i=0; i<s; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    insertionSort(nums, s);
    int index = binarySearch(nums, s, num);
    
    cout << "Sorted Array" << endl;
    for (int i=0; i<s; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    if (index != -1) {
        cout << "Element Found at Index " << index << endl;
    } else {
        cout << "Element Not Found" << endl;
    }

    delete[] nums;
    return 0;
}