#include <iostream>
using namespace std;

struct node {
    int key;
    node* left;
    node* right;
    int h;
    node(int k) { 
        key = k;
        left = right = NULL; 
        h = 1; 
    }
};

int height(node* r) {
    return r ? r->h : 0;
}
int bf(node* r) {
    return height(r->left) - height(r->right);
}

node* rightRotate(node* y) {
    cout << "Rotation: Right Rotation on " << y->key << endl;
    node* x = y->left;
    node* t = x->right;
    x->right = y;
    y->left = t;
    y->h = max(height(y->left), height(y->right)) + 1;
    x->h = max(height(x->left), height(x->right)) + 1;
    return x;
}

node* leftRotate(node* x) {
    cout << "Rotation: Left Rotation on " << x->key << endl;
    node* y = x->right;
    node* t = y->left;
    y->left = x;
    x->right = t;
    x->h = max(height(x->left), height(x->right)) + 1;
    y->h = max(height(y->left), height(y->right)) + 1;
    return y;
}

node* insertn(node* r, int k) {
    if (!r) return new node(k);

    if (k < r->key) {
        r->left = insertn(r->left, k);
    } else if (k > r->key) {
        r->right = insertn(r->right, k);
    } else return r;

    r->h = max(height(r->left), height(r->right)) + 1;

    int b = bf(r);
    cout << "Inserted " << k << ", bf(" << r->key << ")=" << b << endl;

    if (b > 1 && k < r->left->key) return rightRotate(r);
    if (b < -1 && k > r->right->key) return leftRotate(r);
    if (b > 1 && k > r->left->key) {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if (b < -1 && k < r->right->key) {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}

void range(node* r, int x, int y) {
    if (!r) return;
    if (r->key > x) range(r->left, x, y);
    if (r->key >= x && r->key <= y) cout << r->key << " ";
    if (r->key < y) range(r->right, x, y);
}

int main() {
    node* r = NULL;

    int p[] = {100, 40, 200, 150, 300, 90};
    for (int x : p) r = insertn(r, x);

    cout << "range 80 to 200: ";
    range(r, 80, 200);
    cout << endl;

    return 0;
}
