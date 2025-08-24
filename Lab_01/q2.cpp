#include <iostream>
#include <string>

using namespace std;

class Exam {
    private:
        string *name;
        string *date;
        int *score;

    public:
        Exam(string n, string d, int s) {
            name = new string(n);
            date = new string(d);
            score = new int(s);
        }
        void setName(string n) {
            *name = n;
        }

        void setDate(string d) {
            *date = d;
        }

        void setScore(int s) {
            *score = s;
        }

        void display() {
            cout << "Name: " << *name << "\nDate of Exam: " << *date << "\nScore: " << *score << endl; 
        }

        ~Exam() {
            delete name;
            delete date;
            delete score;
        }
};

int main() {
    Exam e1("Muhib", "18/08/2025", 95);
    Exam e2 = e1;

    cout << "Exam 1: \n";
    e1.display();
    cout << "\nExam 2: \n";
    e2.display();

    e2.setName("Ahmed");
    e2.setDate("20/08/2025");
    e2.setScore(89);
    
    cout << "\nUpdated Exam 1: \n";
    e1.display();
    cout << "\nUpdated Exam 2: \n";
    e2.display();

    return 0;
}