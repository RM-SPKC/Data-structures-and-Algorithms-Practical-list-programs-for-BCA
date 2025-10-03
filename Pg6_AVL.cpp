#include <iostream>
#include <cstdlib>    // for exit()
#include <algorithm>  // for max()
using namespace std;
class node {
public:
    int data;
    node *left;
    node *right;
};
class avl {
public:
    node* root;
    avl() {
        root = NULL;
    }
    int height(node*);
    int bf(node*);
    node* rr_rotation(node*);
    node* ll_rotation(node*);
    node* lr_rotation(node*);
    node* rl_rotation(node*);
    node* balance(node*);
    node* insert(node*, int);
    node* remove(node*, int);
    node* minValueNode(node*);
    void display(node*, int);
};
int avl::height(node *t) {
    if (t == NULL)
        return 0;
    return 1 + max(height(t->left), height(t->right));
}
int avl::bf(node *t) {
    if (t == NULL)
        return 0;
    return height(t->left) - height(t->right);
}
node* avl::rr_rotation(node *p) {
    node *t = p->right;
    p->right = t->left;
    t->left = p;
    return t;
}
node* avl::ll_rotation(node *p) {
    node *t = p->left;
    p->left = t->right;
    t->right = p;
    return t;
}
node* avl::lr_rotation(node *p) {
    p->left = rr_rotation(p->left);
    return ll_rotation(p);
}
node* avl::rl_rotation(node *p) {
    p->right = ll_rotation(p->right);
    return rr_rotation(p);
}
node* avl::balance(node *t) {
    int balanceFactor = bf(t);
    if (balanceFactor > 1) {
        if (bf(t->left) >= 0)
            t = ll_rotation(t);
        else
            t = lr_rotation(t);
    } else if (balanceFactor < -1) {
        if (bf(t->right) <= 0)
            t = rr_rotation(t);
        else
            t = rl_rotation(t);
    }
    return t;
}
node* avl::insert(node *root, int value) {
    if (root == NULL) {
        node* n = new node();
        n->data = value;
        n->left = n->right = NULL;
        return n;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;  // Duplicate values not allowed
    return balance(root);
}
node* avl::minValueNode(node* n) {
    node* current = n;
    while (current->left != NULL)
        current = current->left;
    return current;
}
node* avl::remove(node* n, int key) {
    if (!n) return n;
    if (key < n->data)
        n->left = remove(n->left, key);
    else if (key > n->data)
        n->right = remove(n->right, key);
    else {
        // One or no child
        if (!n->left || !n->right) {
            node* t = n->left ? n->left : n->right;
            if (!t) {
                // No child
                t = n;
                n = NULL;
            } else {
                // One child
                *n = *t;
            }
            delete t;
        } else {
            // Two children
            node* t = minValueNode(n->right);
            n->data = t->data;
            n->right = remove(n->right, t->data);
        }
    }
    if (n == NULL)
        return n;
    return balance(n);
}
void avl::display(node *ptr, int level) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);  // Print right subtree first
        cout << "\n";
        for (int i = 0; i < level; i++)
            cout << "         ";  // Indentation per level (8 spaces)
        if (ptr == root)
            cout << "Root -> ";
        else
            cout << "  -> ";
        cout << ptr->data;
        display(ptr->left, level + 1);   // Then print left subtree
    }
}
int main() {
    avl a;
    int choice, value;
    cout << "\n\t\t\tAVL Tree";
        cout << "\n\t\t\t--------";
        cout << "\n1. Insert Element";
        cout << "\n2. Delete Element";
        cout << "\n3. Display Tree";
        cout << "\n4. Exit";
        while (true) {
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                a.root = a.insert(a.root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                a.root=a.remove(a.root,value);
                cout<<"\n\tDeleted Successfully...\n";
                break;
            case 3:
                if (!a.root)
                    cout << "Tree is empty.\n";
                else {
                    cout << "\n\tAVL Tree Structure:";
                    cout << "\n\t-------------------\n";
                    a.display(a.root, 0);
                    cout << "\n";
                }
                break;
            case 4:
                cout << "\n\tExiting...\n";
                exit(0);
            default:
                cout << "\n\tInvalid Choice.Enter the choice between 1-4 .\n";
        }
    }
    return 0;
}

