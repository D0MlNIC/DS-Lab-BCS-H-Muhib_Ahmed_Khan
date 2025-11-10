#include <iostream>
#include <string>

using namespace std;

struct Node {
    string song;
    struct Node* left;
    struct Node* right;
    int playCount;

    Node(string val, int pc) {
        song = val;
        playCount = pc;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, string name, int pc) {
    // Node *temp = root, *prev = root;
    if (root == nullptr) {
        return new Node(name, pc);
    }
    if (pc > root->playCount) 
        root->right = insert(root->right, name, pc);
    else if (pc < root->playCount) {
        root->left = insert(root->left, name, pc);
    } else return root;

    return root;
}

Node *search(Node *root, int pc) {
    if (root == nullptr) return NULL;
    if (pc > root->playCount) return search(root->right, pc);
    else if (pc < root->playCount) return search(root->left, pc);
    else return root; 
}

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->song << ' ' << root->playCount << endl;
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->song << ' ' << root->playCount << endl;
}

Node *findMin(Node *root) {
    if (root->left == nullptr) return root;
    return findMin(root->left);
}

Node *deleteNode(Node *root, int pc) {
    if (root == nullptr) return NULL;
    if (pc < root->playCount) 
        root->left = deleteNode(root->left, pc);
    else if (pc > root->playCount) {
        root->right = deleteNode(root->right, pc);
    } else {
        if (root->left == nullptr) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMin(root);
        root->song = temp->song;
        root->playCount = temp->playCount;
        root->right = deleteNode(root->right, temp->playCount);
    }
    return root;
}

int main() {
    Node *root = insert(nullptr, "S1", 5);
    root = insert(nullptr, "S2", 3);
    root = insert(nullptr, "S3", 7);
    root = insert(nullptr, "S4", 2);
    root = insert(nullptr, "S5", 9);
    root = insert(nullptr, "S6", 11);
    root = insert(nullptr, "S7", 13);

    Node *searched = search(root, 11);
    cout << searched->song << ' ' << searched->playCount << endl;

    // inorder(root);
    // postorder(root);

    // deleteNode(root, 11);

    // inorder(root);
    
    return 0;
}   