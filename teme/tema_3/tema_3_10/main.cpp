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
    static void new_list (LinkedList&, LinkedList&, LinkedList&);

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
void LinkedList::new_list(LinkedList& a, LinkedList& b, LinkedList& c){

    node* p = a.head;
    node* q = b.head;
    while(p != NULL && q != NULL){
        if(p->value < q->value){
            c.tail->next = p;
            c.tail = p;
            p = p->next;
        }else if(p->value > q->value){
            c.tail->next = q;
            c.tail = q;
            q = q->next;
        }else{
            c.tail->next = p;
            c.tail = p;
            p = p->next;
            q = q->next;
        }
    }
    while(p){
        c.tail->next = p;
        c.tail = p;
        p = p->next;
    }
    while(q){
        c.tail->next = q;
        c.tail = q;
        q = q->next;
    }


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

}
int main()
{
    LinkedList a, b, c;
    cin >> a;
    cin >> b;
    LinkedList::new_list(a, b, c);
    cout << c;
    return 0;
}
