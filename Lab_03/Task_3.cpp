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

        Node<T>* reverseKGroup(Node<T>* h, int k) {
            Node<T>* curr = h;
            int count = 0;

            while (curr != nullptr && count < k) {
                curr = curr->next;
                count++;
            }

            if (count == k) {
                Node<T>* prev = reverseKGroup(curr, k);
                curr = h;
                while (count--) {
                    Node<T>* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                return prev;
            }

            return h;
        }

        void reverseListInGroupsOfK(int k) {
            head = reverseKGroup(head, k);
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
    SLL<int> singly1;
    singly1.insertAtEnd(1);
    singly1.insertAtEnd(2);
    singly1.insertAtEnd(3);
    singly1.insertAtEnd(4);
    singly1.insertAtEnd(5);
    singly1.insertAtEnd(6);
    singly1.insertAtEnd(7);
    singly1.insertAtEnd(8);
    singly1.display();
    singly1.reverseListInGroupsOfK(3);
    singly1.display();
    return 0;
}