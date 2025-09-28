#include <iostream>

using namespace std;

int sumNonTail(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumNonTail(n-1);
}

int sumTail(int n, int sum) {
    if (n == 1) {
        return 1+sum;
    }
    return sumTail(n-1, sum+n);
}

int main() {
    cout << "Sum Tail: " << sumTail(5, 0) << endl;
    cout << "Sum Non Tail: " << sumNonTail(5) << endl;
    return 0;
}