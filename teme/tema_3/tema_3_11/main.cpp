#include <iostream>

using namespace std;
struct node{

    int value;
    node* next;

};
class LinkedList{

public:
    node *head, *tail;
public:
    LinkedList();
    ~LinkedList();
    void AddElement(int);
    friend ostream& operator << (ostream&, const LinkedList&);
    friend istream& operator >> (istream&, LinkedList&);
    static void new_lists(const LinkedList&);

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
void LinkedList::new_lists(const LinkedList& c){

    node *a, *b, *temp_a, *temp_b;
    if(c.head == NULL){
        cout << "no elements in the list" << endl;
        return;
    }
    if(c.head->next == NULL){
        a = c.head;
        cout << "1st List" << endl;
        cout << a->value << endl;
        cout << "2st List" << endl;
        cout << "no elements in this list";
        return;
    }
    if(c.head->next->next == NULL){
        a = c.head;
        b = c.head->next;
        temp_a = a;
        temp_b = b;
        temp_a = temp_a->next->next;
        a->next = temp_a;
        cout << "1st List" << endl;
        while(a){
        cout << a->value << " ";
        a = a->next;
        }
        cout << endl;
        cout << "2nd List" << endl;
        cout << temp_b->value;
        return;
    }
    node* p = c.head;
    a = c.head;
    b = c.head->next;
    temp_a = a->next->next;
    temp_b = b->next->next;
    a->next = temp_a;
    b->next = temp_b;
    while(temp_a->next && temp_b->next){
        node* temp_a_next = temp_a->next->next;
        node* temp_b_next = temp_b->next->next;
        temp_a->next = temp_a_next;
        temp_b->next = temp_b_next;
        temp_a = temp_a->next;
        temp_b = temp_b->next;
    }
    temp_a->next = NULL;
    cout << "1st List" << endl;
    while(a){
        cout << a->value << " ";
        a = a->next;
    }
    cout << endl;
    cout << "2nd List" << endl;
    while(b){
        cout << b->value << " ";
        b = b->next;
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
int main()
{
    LinkedList c;
    cin >> c;
    cout << c;
    LinkedList::new_lists(c);
    return 0;
}
