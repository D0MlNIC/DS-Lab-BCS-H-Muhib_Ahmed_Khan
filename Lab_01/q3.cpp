#include <iostream>
#include <string>

using namespace std;

class Box {
    private:
        int *size;

    public:
        Box() {
            size = new int(1);
        }

        Box(int s) {
            size = new int(s);
        }

        Box(Box &b) {
            size = new int(*b.size);
        }

        Box& operator= (Box &b) {
            int s = *b.size;
            Box box(s);
            return box;
        }

        friend ostream& operator<< (ostream &os, Box &b);
};

ostream& operator<< (ostream &os, Box &b) {
    os << " Size: " << *b.size << endl;
    return os;
}

int main() {
    Box b1;
    Box b2(10);
    Box b3(b2);
    Box b4 = b3;

    cout << "Box 1" << b1;
    cout << "Box 2" << b2;
    cout << "Box 3" << b3;
    cout << "Box 4" << b4;
}