#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    struct Node* left;
    struct Node* right;
    int level;

    Node(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(Node *root) {
    if (root == nullptr) return 0;
    int h1 = 1 + getHeight(root->left);
    int h2 = 1 + getHeight(root->right);
    return max(h1, h2);
}

void setLevels(Node *root, int l) {
    if (root == nullptr) return;
    root->level = l+1;
    setLevels(root->left, l+1);
    setLevels(root->right, l+1);
}

int main() {
    Node *root = new Node("me");
    Node *mother = new Node("mom");
    Node *father = new Node("dad");
    Node *momMother = new Node("mom Mother");
    Node *momFather = new Node("mom Father");
    Node *dadMother = new Node("dad Mother");
    Node *dadFather = new Node("dad Father");

    root->left = mother;
    root->right = father;
    mother->left = momMother;
    mother->right = momFather;
    father->left = dadMother;
    father->right = dadFather;

    cout << "Root Node: " << root->data << endl;
    cout << "Leaf Nodes:" << endl;
    cout << momMother->data << endl;
    cout << momFather->data << endl;
    cout << dadMother->data << endl;
    cout << dadFather->data << endl;

    cout << "Height = " << getHeight(root) << endl;

    setLevels(root, -1);
    cout << "Levels: " << endl;
    cout << "Root Level: " << root->level << endl;
    cout << "Root Mother Level: " << root->left->level << endl;
    cout << "Root Father Level: " << root->right->level << endl;
    cout << "Root Mother Mother Level: " << root->left->left->level << endl;
    cout << "Root Mother Father Level: " << root->left->right->level << endl;
    cout << "Root Father Mother Level: " << root->right->left->level << endl;
    cout << "Root Father Father Level: " << root->right->right->level << endl;
    
    return 0;
}