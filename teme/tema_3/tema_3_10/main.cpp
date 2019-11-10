#include <iostream>

using namespace std;
struct node{

    int value;
    node* next;

};
class LinkedList{

public:
    node *head, *tail;
    int number_of_elements;
    LinkedList();
    void AddElement(int);
    static node* merge_lists(node*, node*);
    friend ostream& operator << (ostream&, const LinkedList&);
    friend istream& operator >> (istream&, LinkedList&);

};
node* LinkedList::merge_lists(node* a, node* b){

    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node* head;
    if(a->value < b->value){
        head = a;
    }else{

        head = b;
        b = a;
        a = head;
    }
    while(a->next != NULL){
        if(a->next->value > b->value){
            node* temp = a->next;
            a->next = b;
            b = temp;
        }
        a = a->next;
    }
    a->next = b;
    return head;

}
LinkedList::LinkedList(){

    head = NULL;
    tail = NULL;
    number_of_elements = 0;

}
istream& operator >> (istream& in, LinkedList& l){

    cout << "New List" << endl;
    cout << "Number of elements in the list:" << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int new_value;
        cin >> new_value;
        l.AddElement(new_value);
    }

    return in;

}
ostream& operator << (ostream& out, const LinkedList& l){

    node* p = l.head;
    while(p){
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;

    return out;

}
void LinkedList::AddElement(int new_value){

    node* q =  new node;
    q->value = new_value;
    q->next = NULL;
    if(head == NULL){
        head = q;
        tail = q;
        q = NULL;
    }else{
        tail->next = q;
        tail = q;
    }
    number_of_elements++;

}
int main()
{
    LinkedList a, b;
    cout << "List 1." << endl;
    cin >> a;
    cout << a;
    cout << "List 2." << endl;
    cin >> b;
    cout << b;
    node* new_list = LinkedList::merge_lists(a.head, b.head);
    while(new_list != NULL){
        cout << new_list->value << " ";
        new_list = new_list->next;
    }
    return 0;
}
