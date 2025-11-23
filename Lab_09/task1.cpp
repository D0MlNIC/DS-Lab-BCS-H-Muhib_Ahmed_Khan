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

node* minnode(node* r) {
    while (r->left) r = r->left;
    return r;
}

node* deleteNode(node* r, int k) {
    if (!r) return r;

    if (k < r->key) r->left = deleteNode(r->left, k);
    else if (k > r->key) r->right = deleteNode(r->right, k);
    else {
        if (!r->left || !r->right) {
            node* x = r->left ? r->left : r->right;
            if (!x) { delete r; return NULL; }
            *r = *x;
            delete x;
        } else {
            node* x = minnode(r->right);
            r->key = x->key;
            r->right = deleteNode(r->right, x->key);
        }
    }

    if (!r) return r;

    r->h = max(height(r->left), height(r->right)) + 1;

    int b = bf(r);
    cout << "Deleted " << k << ", bf(" << r->key << ")=" << b << endl;

    if (b > 1 && bf(r->left) >= 0) return rightRotate(r);
    if (b > 1 && bf(r->left) < 0) {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if (b < -1 && bf(r->right) <= 0) return leftRotate(r);
    if (b < -1 && bf(r->right) > 0) {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

int main() {
    node* r = NULL;

    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) {
        r = insertn(r, x);
        cout << "Height: " << height(r) << endl << endl;
    }

    r = deleteNode(r, 20);
    cout << "Height: " << height(r) << endl << endl;

    r = deleteNode(r, 30);
    cout << "Height: " << height(r) << endl << endl;

    r = deleteNode(r, 70);
    cout << "Height: " << height(r) << endl << endl;

    return 0;
}
