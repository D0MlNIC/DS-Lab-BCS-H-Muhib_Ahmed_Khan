#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class MLL;

template <typename T>
class Node {
    public:
        T data;
        Node *next;
        MLL<T> *mll;

        Node() {
            next = NULL;
            mll = NULL;
        }

        Node(T dat) : data(dat) {
            next = NULL;
            mll = NULL;
        }
};

template <typename T>
class MLL {
    public:
        Node<T> *head;
        Node<T> *tail;
        int length;

        MLL() {
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

        void flatten() {
            int i=0;
            Node<T> *temp = head;
            Node<T> *stemp;
            while (temp != NULL) {
                if (temp->mll != NULL) {
                    stemp = temp->mll->head;
                    cout << i << endl;
                    while (stemp != NULL) {
                        insertAtMiddle(i, stemp->data);
                        stemp = stemp->next;
                        i++;
                    }
                }
                temp = temp->next;
                i++;
            }
        }

        ~MLL() {
            Node<T> *temp = head;
            Node<T> *next = temp->next;
            do {
                delete temp;
                temp = next;
                next = temp->next;
            } while (temp->next != NULL);
            cout << "Deleted MLL" << endl;
        }
};

int main() {
    MLL<int> *mll1 = new MLL<int>();
    MLL<int> *mll2 = new MLL<int>();
    mll2->insertAtEnd(4);
    mll2->insertAtEnd(5);
    mll1->insertAtEnd(1);
    mll1->insertAtEnd(2);
    mll1->tail->mll = mll2;
    mll1->insertAtEnd(3);

    cout << "List 1 ";
    mll1->display();
    cout << "List 2 ";
    mll2->display();

    mll1->flatten();
    mll1->display();

    delete mll2;
    delete mll1;
    return 0;
}