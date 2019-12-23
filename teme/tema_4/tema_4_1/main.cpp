#include <iostream>

using namespace std;
struct node{

    int value;
    node* left;
    node* right;

};
class binarySearchTree{

public:
    node *root;
    binarySearchTree();
    void insert_node(int);
    int search_node(int);
    int findMax();
    node* findMinNode(node*);
    static void RSD(node*);
    static void SRD(node*);
    static void SDR(node*);
    node* delete_node(node*, int);
    friend istream& operator >> (istream&, binarySearchTree&);
};
binarySearchTree::binarySearchTree(){

    root = NULL;

}
void binarySearchTree::insert_node(int a){

    node* q = new node;
    q->value = a;
    q->right = NULL;
    q->left = NULL;
    if(root == NULL){
        root = q;
    }
    node* p = root;
    if(p->value > a && p->left == NULL) {
        p->left = q;

    } else if(p->value < a && p->right == NULL) {
        p->right = q;
    }
    while(p->left != NULL || p->right != NULL) {
        if(p->value == a) {
            return;
        } else if(p->value > a) {
            if(p->left != NULL) {
                p = p->left;
            } else {
                p->left = q;
            }
        } else if(p->value < a) {
            if(p->right != NULL) {
                p = p->right;
            } else {
                p->right = q;
            }
        }
    }
    if(p->value == a) {
        return;
    } else if (p->value > a) {
        p->left = q;
    } else {
        p->right = q;
    }

}
int binarySearchTree::search_node(int a){

    if(root == NULL) {
        return 0;
    }
    node* p = root;
    if(p->value == a) {
        return 1;
    } else {
        while(p) {
            if(p->value == a) {
                return 1;
            } else if (p->value > a) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
    }
    return 0;

}
int binarySearchTree::findMax(){

    node* p = root;
    while(p->right != NULL){
        p = p->right;
    }
    return p->value;

}
node* binarySearchTree::findMinNode(node* root_) {

    node* p = root_;
    while(p && p->left != NULL) {
        p = p->left;
    }
    return p;

}
void binarySearchTree::RSD(node* root_){
    //pre order
    if(root_) {
    cout << root_->value << " ";
    binarySearchTree::RSD(root_->left);
    binarySearchTree::RSD(root_->right);
    }

}
void binarySearchTree::SRD(node* root_){
    //in-order
    if(root_) {
        binarySearchTree::SRD(root_->left);
        cout << root_->value << " ";
        binarySearchTree::SRD(root_->right);
    }
}
void binarySearchTree::SDR(node* root_){
    //post order
    if(root_) {
        binarySearchTree::SDR(root_->left);
        binarySearchTree::SDR(root_->right);
        cout << root_->value << " ";
    }
}
node* binarySearchTree::delete_node(node* root_, int a) {

    if(root_ ==  NULL) {
        return root_;
    }
    if(a < root_->value) {
        root_->left = binarySearchTree::delete_node(root_->left, a);
    } else if(a > root_->value) {
        root_->right = binarySearchTree::delete_node(root_->right, a);
    } else {
        if(root_->left == NULL) {
            node* temp = root_->right;
            delete root_;
            return temp;
        } else if(root_->right == NULL) {
            node* temp = root_->left;
            delete root_;
            return temp;
        }
        node* temp = binarySearchTree::findMinNode(root_->right);
        root_->value = temp->value;
        root_->right = delete_node(root_->right, temp->value);
    }
    return root_;

}
istream& operator >> (istream& in, binarySearchTree& bst){

    cout << "Numarul de elemente din arbore" << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int new_value;
        cin >> new_value;
        bst.insert_node(new_value);
    }
    return in;

}
void menu(binarySearchTree& bst) {

    cout << "Introduceti o optiune" << endl;
    int x;
    cin >> x;
    while(x) {

        switch(x) {
            case 1: {
                cout << "a = ";
                int a;
                cin >> a;
                cout << endl;
                bst.insert_node(a);
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;
            case 2: {
                cout << "a = ";
                int a;
                cin >> a;
                cout << bst.search_node(a) << endl;
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;
            case 3: {
                cout << bst.findMax() << endl;
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;
            case 4: {
                binarySearchTree::RSD(bst.root);
                cout << endl;
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;
            case 5: {
                binarySearchTree::SRD(bst.root);
                cout << endl;
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;
            case 6: {
                binarySearchTree::SDR(bst.root);
                cout << endl;
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;
            case 7: {
                cout << "a = ";
                int a;
                cin >> a;
                bst.root = bst.delete_node(bst.root, a);
                cout << "Introduceti o optiune" << endl;
                cin >> x;
            }
            break;

        }
    }

}
int main()
{
    binarySearchTree bst;
    menu(bst);
    return 0;
}
