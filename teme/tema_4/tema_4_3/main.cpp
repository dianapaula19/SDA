#include <iostream>

using namespace std;
struct node{

    int value;
    int left_size;
    node* left;
    node* right;

};
class binaryIndexedTree{

public:
    node *root;
    binaryIndexedTree();
    void insert_node(int);
    static int calculateLeftSize(node*);
    static int searchIndex(node*, int);
    static void SRD(node*);
    friend istream& operator >> (istream&, binaryIndexedTree&);
};
binaryIndexedTree::binaryIndexedTree(){

    root = NULL;

}
void binaryIndexedTree::insert_node(int a){

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
binaryIndexedTree::calculateLeftSize(node* root_sub_tree) {

    int number = 1;
    if(root_sub_tree == NULL) {
        return 0;
    } else {
        number += binaryIndexedTree::calculateLeftSize(root_sub_tree->left);
        number += binaryIndexedTree::calculateLeftSize(root_sub_tree->right);
        return number;
    }

}
binaryIndexedTree::searchIndex(node* root_, int index) {

    if(index == root_->left_size) {
        return root_->value;
    } else if (index < root_->left_size) {
        return searchIndex(root_->left, index);
    } else if (index > root_->left_size) {
        return index - root_->left_size - 1;
    }
    return 0;

}
void binaryIndexedTree::SRD(node* root_){

    if(root_) {
        binaryIndexedTree::SRD(root_->left);
        if(root_->left != NULL) {
            root_->left_size = binaryIndexedTree::calculateLeftSize(root_->left);
        } else {
            root_->left_size = 0;
        }
        cout << root_->value << " " << root_->left_size << "\n";
        binaryIndexedTree::SRD(root_->right);
    }
}
istream& operator >> (istream& in, binaryIndexedTree& bit){

    cout << "Numarul de elemente din arbore" << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int new_value;
        cin >> new_value;
        bit.insert_node(new_value);
    }
    return in;

}
int main()
{
    binaryIndexedTree bit;
    cin >> bit;
    binaryIndexedTree::SRD(bit.root);
    cout << "Pozitia este:\n";
    int k;
    cin >> k;
    cout << binaryIndexedTree::searchIndex(bit.root, k);
    return 0;
}
