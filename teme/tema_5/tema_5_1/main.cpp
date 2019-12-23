#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;

class Node {

public:
    int value;
    int height;
    Node* left;
    Node* right;
    Node();
    Node(int);
    int getBalance();

};
Node::Node() {

    value = 0;
    height = 0;
    left = nullptr;
    right = nullptr;

}
Node::Node(int new_value) {

    value = new_value;
    height = 1;
    left = nullptr;
    right = nullptr;

}
int Node::getBalance() {

    return (this->left->height - this->right->height);

}
class AVLTree {

public:
    Node* root;
    AVLTree();
    static Node* rightRotate(Node*);
    static Node* leftRotate(Node*);
    static Node* add_key(Node*, int);
    static void print_pre_order(Node*);
    static void print_in_order(Node*);
    friend istream& operator >> (istream&, AVLTree&);
};
AVLTree::AVLTree() {

    root = nullptr;

}
Node* AVLTree::rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    if (y->left->height > y->right->height) {
        y->height = y->left->height + 1;
    } else {
        y->height = y->right->height + 1;
    }
    if (x->left->height > x->right->height) {
        x->height = x->left->height + 1;
    } else {
        x->height = x->right->height + 1;
    }

    return x;
}
Node* AVLTree::leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    if (y->left->height > y->right->height) {
        y->height = y->left->height + 1;
    } else {
        y->height = y->right->height + 1;
    }
    if (x->left->height > x->right->height) {
        x->height = x->left->height + 1;
    } else {
        x->height = x->right->height + 1;
    }

    return y;
}
Node* AVLTree::add_key(Node* root, int new_value) {

    // creates the very first key of the AVL Tree
    if (root == nullptr) {
        return new Node(new_value);
    }

    if (root->value > new_value) {
        root->left = AVLTree::add_key(root->left, new_value);
    } else if (root->value < new_value) {
        root->right = AVLTree::add_key(root->right, new_value);
    } else {
        return root;
    }
    if (root->left != nullptr && root->right == nullptr) {
        root->height = root->left->height + 1;
    } else if (root->left == nullptr && root->right != nullptr) {
        root->height = root->right->height + 1;
    } else if (root->left != nullptr && root->right != nullptr) {
        if (root->left->height > root->right->height) {
            root->height = root->left->height + 1;
        } else {
            root->height = root->right->height + 1;
        }
    }
        /*
    int balance = root->getBalance();

    if (balance > 1 && new_value < root->left->value) {
        return AVLTree::leftRotate(root);
    }
    if (balance < -1 && new_value > root->right->value) {
        return AVLTree::leftRotate(root);
    }
    if (balance > 1 && new_value > root->left->value) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && new_value < root->right->value) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    */
    return root;
}
void AVLTree::print_pre_order(Node* root) {

    if (root != nullptr) {
        cout << root->value << " ";
        print_pre_order(root->left);
        print_pre_order(root->right);
    }

}
void AVLTree::print_in_order(Node* root) {

    if (root != nullptr) {
        print_in_order(root->left);
        cout << root->value << " ";
        print_in_order(root->right);
    }

}
istream& operator >> (istream& in, AVLTree& avl_tree) {

    cout << "Adaugati numarul de elemente din arbore:\n";
    int n;
    in >> n;
    for(int i = 0; i < n; ++i) {
        cout << "element nou = ";
        int new_value;
        in >> new_value;
        avl_tree.root = AVLTree::add_key(avl_tree.root, new_value);

    }
    return in;

}

void menu(AVLTree& avl_tree) {

    cout << "1-adauga o cheie noua\n";
    cout << "2-RSD\n";
    cout << "3-SDR\n";
    cout << "Optiunea dorita: ";
    int op;
    cin >> op;
    while(op) {
        switch(op) {
            case 1: {
                cout << "Adaugati un element nou: ";
                int new_value;
                cin >> new_value;
                avl_tree.root = AVLTree::add_key(avl_tree.root, new_value);
                cout << "\n";
                cout << "1-adauga o cheie noua\n";
                cout << "2-RSD\n";
                cout << "3-SDR\n";
                cout << "Optiunea dorita: ";
                cin >> op;
            }
            break;
            case 2: {
                cout << "RSD\n";
                AVLTree::print_pre_order(avl_tree.root);
                cout << "\n";
                cout << "1-adauga o cheie noua\n";
                cout << "2-RSD\n";
                cout << "3-SDR\n";
                cout << "Optiunea dorita: ";
                cin >> op;
            }
            break;
            case 3: {
                cout << "SDR\n";
                AVLTree::print_in_order(avl_tree.root);
                cout << "\n";
                cout << "1-adauga o cheie noua\n";
                cout << "2-RSD\n";
                cout << "3-SDR\n";
                cout << "Optiunea dorita: ";
                cin >> op;
            }
            break;
            }
        }
}
int main()
{
    AVLTree avl_tree;
    cin >> avl_tree;
    menu(avl_tree);
    return 0;
}
