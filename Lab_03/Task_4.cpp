#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;

        Node() {
            next = NULL;
        }

        Node(T dat) : data(dat) {
            next = NULL;
        }
};

template <typename T>
class CLL {
    public:
        Node<T> *head;
        Node<T> *tail;
        int length;

        CLL() {
            head = NULL;
            tail = NULL;
            length = 0;
        }

        void insertAtStart(T val) {
            Node<T> *newNode = new Node<T>(val);
            if (head == NULL) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            tail = head;
            head->next = head;
            length++;
        }

        void insertAtEnd(T val) {
            // Node<T> *temp = head;
            // while (temp->next != NULL) {
            //     temp = temp->next;
            // }
            Node<T> *newNode = new Node<T>(val);
            if (head == NULL && tail == NULL) {
                head = newNode;
                tail = newNode;
            }
            tail->next = newNode;
            tail = newNode;
            newNode->next = head;
            length++;
        }

        void insertAtMiddle(int index, T val) {
            if (index < 0) cout << "Not Possible" << endl;
            int i = 0;
            Node<T> *temp = head;
            while (i != index && temp->next != NULL) {
                temp = temp->next;
                i++;
            }
            Node<T> *newNode = new Node<T>(val);
            if (temp->next == NULL) {
                tail = newNode;
                newNode->next = head;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (index == 0) {
                head = newNode;
                newNode->next = head;
            }
            length++;
        }

        void display() {
            Node<T> *temp = head;
            cout << "Data: ";
            while (temp->next != head) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << " " << endl;
        }

        T josephusProblem(int k) {
            Node<T> *permHead = head;
            Node<T> *temp = head;
            Node<T> *next, *prev;
            while (temp->next != temp) {
                int i = 1;
                while (i < k) {
                    prev = temp;
                    temp = temp->next;
                    i++;
                }
                next = temp->next;
                delete temp;
                prev->next = next;
                temp = next;
            }
            head = temp;
            return temp->data;
        }

        ~CLL() {
            Node<T> *temp = head;
            Node<T> *next = temp->next;
            if (temp->next == head) {
                delete temp;
            } else {
                do {
                    delete temp;
                    temp = next;
                    next = temp->next;
                } while (temp->next != NULL);
            }
            cout << "Deleted SLL" << endl;
        }
};

int main() {
    CLL<int> singly1;
    for (int i=1; i<=7; i++) {
        singly1.insertAtEnd(i);
    }
    singly1.display();
    cout << "Position of Survivor: " << singly1.josephusProblem(3) << endl;
    return 0;
}