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
            int i = 0;
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

        void display() {
            Node<T> *temp = head;
            cout << "Data: ";
            while (temp->next != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << " " << endl;
        }

        void mergeList(SLL *ll) {
            Node<T> *shead = ll->head;
            Node<T> *temp;
            Node<T> *temp1 = head;
            Node<T> *temp2 = shead;

            do {
                temp = temp1->next;
                temp1->next = temp2;
                temp2 = temp2->next;
                temp1->next->next = temp;
                temp1 = temp;
            } while (temp2->next != NULL);
            tail->next = temp2;
            tail = tail->next;
            ll->head = NULL;
            cout << "Sucessfully Merged two lists." << endl;
        }

        ~SLL() {
            Node<T> *temp = head;
            Node<T> *next = temp->next;
            do {
                delete temp;
                temp = next;
                next = temp->next;
            } while (temp->next != NULL);
            cout << "Deleted SLL" << endl;
        }
};

int main() {
    SLL<char> *singly1 = new SLL<char>();
    singly1->insertAtEnd('a');
    singly1->insertAtEnd('c');
    singly1->insertAtEnd('e');

    SLL<char> *singly2 = new SLL<char>();
    singly2->insertAtEnd('b');
    singly2->insertAtEnd('d');
    singly2->insertAtEnd('f');
    singly1->display();
    singly2->display();
    singly1->mergeList(singly2);
    singly1->display();
    delete singly1;
    return 0;
}