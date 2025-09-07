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

        bool isPalindrome() {
            Node<T> *mid;
            Node<T> *tempmid;
            Node<T> *temp = head;
            int i=0;
            while (length/2 != i) {
                temp = temp->next;
                i++;
            }
            SLL<char> rev;
            if (length % 2 != 0) {
                temp = temp->next;
            }
            while (temp->next != NULL) {
                rev.insertAtStart(temp->data);
                temp = temp->next;
            }
            rev.insertAtStart(temp->data);
            temp = head;
            tempmid = rev.head;
            while (tempmid->next != NULL) {
                if (temp->data != tempmid->data) {
                    return false;
                }
                temp = temp->next;
                tempmid = tempmid->next;
            }
            return true;
        }

        ~SLL() {
            Node<T> *temp = head;
            Node<T> *next = temp->next;
            do {
                delete temp;
                temp = next;
                next = temp->next;
            } while (temp->next != NULL);

        }
};

int main() {
    SLL<char> singly;
    singly.insertAtStart('a');
    singly.insertAtStart('b');
    singly.insertAtStart('c');
    singly.insertAtStart('d');
    singly.insertAtStart('c');
    singly.insertAtStart('b');
    singly.insertAtStart('a');
    singly.display();
    int res = singly.isPalindrome();
    cout << "Linked List " << (res == true ? "Is Palindrome" : "Is Not Palindrome") << endl;
    return 0;
}