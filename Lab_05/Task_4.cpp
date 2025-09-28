#include <iostream>

using namespace std;

int ackermann(int m, int n) {
    if (m == 0) return n+1;
    else if (m > 0 && n == 0) return ackermann(m-1, 1);
    else if (m > 0 && n > 0) return ackermann(m-1, ackermann(m, n-1));
} 

int main() {
    cout << ackermann(4, 5) << endl;
    return 0;
}