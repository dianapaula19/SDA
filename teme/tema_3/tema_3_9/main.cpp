#include <iostream>

using namespace std;
struct node{

    int value;
    node* next;

};
class LinkedList{

private:
    node *head, *tail;
public:
    LinkedList();
    ~LinkedList();
    void AddElement(int);
    void AddElementAtTheStart(int);
    friend ostream& operator << (ostream&, const LinkedList&);
    friend istream& operator >> (istream&, LinkedList&);
    static void new_reverse_list(LinkedList&, LinkedList&);
    void same_reverse_list();

};
LinkedList::LinkedList(){

    head = NULL;
    tail = NULL;

}
LinkedList::~LinkedList(){

    node* p = head;
    while(p){
        head = head->next;
        delete p;
        p = head;
    }

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
void LinkedList::AddElementAtTheStart(int new_value){

    node* q = new node;
    q->value = new_value;
    q->next = NULL;
    if(head == NULL){
        head = q;
        tail = q;
        q = NULL;
    }else{
        q->next = head;
        head = q;
    }

}
void LinkedList::AddElement(int new_value){

    node* q = new node;
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

}
void LinkedList::new_reverse_list(LinkedList& a, LinkedList& b){

    cout << "New List" << endl;
    node* p = a.head;
    while(p != NULL){
        b.AddElementAtTheStart(p->value);
        p = p->next;
    }

}
void LinkedList::same_reverse_list(){

    cout << "Same List" << endl;
    node *p, *c, *n;
    c = head;
    p = NULL;
    n = NULL;
    while(c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;

}
int main()
{
    LinkedList a, b;
    cin >> a;
    LinkedList::new_reverse_list(a, b);
    cout << b;
    a.same_reverse_list();
    cout << a;
    return 0;
}

