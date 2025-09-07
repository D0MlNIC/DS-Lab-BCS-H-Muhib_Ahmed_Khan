#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;
        Node *prev;

        Node() {
            next = NULL;
            prev = NULL;
        }

        Node(T dat) : data(dat) {
            next = NULL;
            prev = NULL;
        }
};

template <typename T>
class SLL {
    public:
        Node<T> *head;
        Node<T> *tail;
        int length;

        SLL() {
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
            length++;
        }

        void insertAtMiddle(int index, T val) {
            if (index < 0) cout << "Not Possible" << endl;
            int i = 1;
            Node<T> *temp = head;
            while (i != index && temp->next != NULL) {
                temp = temp->next;
                i++;
            }
            Node<T> *newNode = new Node<T>(val);
            if (temp->next == NULL) tail = newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            if (index == 0) head = newNode;
            length++;
        }

        void convertToCircular() {
            tail->next = head;
        }

        void convertToDoubly() {
            Node<T> *temp = head;
            Node<T> *previous = temp;
            temp = temp->next;
            while (temp != NULL) {
                temp->prev = previous;
                previous = temp;
                temp = temp->next;
            }
        }
        
        void display() {
            Node<T> *temp = head;
            cout << "Data: ";
            while (temp->next != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }

        void displayCircular() {
            Node<T> *temp = head;
            cout << "Data: " << temp->data << " -> ";
            temp = temp->next;
            while (temp != head) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << " (Back To The Start)" << endl;
        }

        void displayDoubly() {
            cout << "Front To Back ";
            display();
            cout << "Back To Front ";
            Node<T> *temp = tail;
            cout << "Data: ";
            while (temp->prev != NULL) {
                cout << temp->data << " -> ";
                temp = temp->prev;
            }
            cout << temp->data << endl;
        }

        ~SLL() {
            Node<T> *temp = head;
            Node<T> *next = temp->next;
            if (temp->next == head) {
                delete temp;
            } else {
                do {
                    delete temp;
                    temp = next;
                    next = temp->next;
                } while (temp->next != NULL && temp != head);
            }
            cout << "Deleted SLL" << endl;
        }
};

int main() {
    SLL<int> singlyC;
    SLL<int> singlyD;
    for (int i=1; i<=5; i++) {
        singlyC.insertAtEnd(i);
        singlyD.insertAtEnd(i);
    }
    cout << "Original ";
    singlyC.display();

    singlyC.convertToCircular();
    singlyC.displayCircular();

    singlyD.convertToDoubly();
    singlyD.displayDoubly();
    return 0;
}