#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int shellSort(int *nums, int s) {
    int countCheck = 0;

    for (int gap = s/2; gap > 0; gap /= 2) {
        for (int j = gap; j < s; j++) {
            int temp = nums[j];
            int res = j;

            while(res >= gap && nums[res - gap] > temp) {
                countCheck++;
                nums[res] = nums[res - gap];
                res -= gap;
            }

            nums[res] = temp;
        }
    }

    return countCheck;
}

long long int bubbleSort(int *nums, int s) {
    long long int countCheck;

    bool swapp = false;
    for (int i=0; i<s; i++) {
        swapp = false;
        for (int j=i+1; j<s; j++) {
            if (nums[j] < nums[i]) {
                countCheck++;
                swap(nums[j], nums[i]);
                swapp = true;
            }
        }
        if (swapp == false) {
            break;
        }
    }

    return countCheck;
}

int insertionSort(int *nums, int s) {
    int countCheck = 0;

    for (int i=1; i<s; i++) {
        int key = nums[i];
        int j = i-1;
        
        while(j >= 0 && nums[j] > key) {
            countCheck++;
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = key;
    }

    return countCheck;
}

int main() {
    int s = 10000;

    int *numsB = new int[s];
    int *numsI = new int[s];
    int *numsS = new int[s];
    int temp;

    srand(time(0));

    for (int i=0; i<s; i++) {
        temp = rand() % 10000;
        numsB[i] = temp;
        numsI[i] = temp;
        numsS[i] = temp;
    }

    auto timestampba = high_resolution_clock::now();
    long long int cb = bubbleSort(numsB, s);
    auto timestampbb = high_resolution_clock::now();
    auto timestampia = high_resolution_clock::now();
    int ci = insertionSort(numsI, s);
    auto timestampib = high_resolution_clock::now();
    auto timestampsa = high_resolution_clock::now();
    int cs = shellSort(numsS, s);
    auto timestampsb = high_resolution_clock::now();

    cout << "Bubble Sort Comparisons: " << cb << endl;
    cout << "Insertion Sort Comparisons: " << ci << endl;
    cout << "Shell Sort Comparisons: " << cs << endl << endl;

    cout << "Bubble Sort Time Taken: " << duration_cast<milliseconds>(timestampbb - timestampba).count() << "ms" << endl;
    cout << "Insertion Sort Time Taken: " << duration_cast<milliseconds>(timestampib - timestampia).count() << "ms" << endl;
    cout << "Shell Sort Time Taken: " << duration_cast<milliseconds>(timestampsb - timestampsa).count() << "ms" << endl;

    delete[] numsB;
    delete[] numsI;
    delete[] numsS;

    return 0;
}