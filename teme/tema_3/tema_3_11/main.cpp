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
    friend ostream& operator << (ostream&, const LinkedList&);
    friend istream& operator >> (istream&, LinkedList&);
    static void new_lists(LinkedList&, LinkedList&, LinkedList&);

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
void LinkedList::new_lists(LinkedList& a, LinkedList& b, LinkedList& c){

    node* p = c.head;
    int i = 0;
    while(p != NULL){
        if(i % 2 == 0){
            b.AddElement(p->value);
        }else{
            a.AddElement(p->value);
        }
        p = p->next;
        i++;
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
    LinkedList a, b, c;
    cin >> c;
    LinkedList::new_lists(a, b, c);
    cout << a;
    cout << b;
    return 0;
}
