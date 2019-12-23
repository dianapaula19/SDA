#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::istream;

struct node{

    string value;
    node* left;
    node* right;

};
class binarySearchTree{

public:
    node *root;
    binarySearchTree();
    void insert_node(string);
    static void SRD(node*);
    static void SDR(node*);
    friend istream& operator >> (istream&, binarySearchTree&);
};
binarySearchTree::binarySearchTree(){

    root = NULL;

}
void binarySearchTree::insert_node(string a){

    node* q = new node;
    q->value = a;
    q->right = NULL;
    q->left = NULL;
    if(root == NULL){
        root = q;
    }
    node* p = root;
    if(p->value < a && p->left == NULL) {
        p->left = q;

    } else if(p->value > a && p->right == NULL) {
        p->right = q;
    }
    while(p->left != NULL || p->right != NULL) {
        if(p->value == a) {
            return;
        } else if(p->value < a) {
            if(p->left != NULL) {
                p = p->left;
            } else {
                p->left = q;
            }
        } else if(p->value > a) {
            if(p->right != NULL) {
                p = p->right;
            } else {
                p->right = q;
            }
        }
    }
    if(p->value == a) {
        return;
    } else if (p->value < a) {
        p->left = q;
    } else {
        p->right = q;
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
istream& operator >> (istream& in, binarySearchTree& bst){

    cout << "Numarul de siruri\n";
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string new_string;
        cin >> new_string;
        bst.insert_node(new_string);
    }
    return in;

}
int main()
{
    binarySearchTree bst;
    cin >> bst;
    binarySearchTree::SRD(bst.root);
    return 0;
}
