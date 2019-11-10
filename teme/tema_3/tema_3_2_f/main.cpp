#include <iostream>

using namespace std;
struct node{

    int value, killed = 0;
    node* next;

};
class LinkedList{

private:
    node *last;
public:
    LinkedList();
    void AddElement(int);
    void AddElementAtTheStart(int);
    friend ostream& operator << (ostream&, const LinkedList&);
    friend istream& operator >> (istream&, LinkedList&);
    int the_last_one_left_alive(int, int);

};
LinkedList::LinkedList(){

    last = NULL;

}
istream& operator >> (istream& in, LinkedList& l){

    cout << "New List" << endl;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        l.AddElement(i);
    }

    return in;

}
ostream& operator << (ostream& out, const LinkedList& l){

    node* p = l.last->next;
    while(p != l.last){
        cout << p->value << " ";
        p = p->next;
    }
    cout << l.last->value << " ";
    cout << endl;

    return out;

}
void LinkedList::AddElement(int new_value){

    node* q = new node;
    q->value = new_value;
    q->next = q;
    if(last == NULL){
        last = q;
    }else{
        q->next = last->next;
        last->next = q;
        last = q;
    }

}
int LinkedList::the_last_one_left_alive(int k, int n){

    int i = 1;
    node* p;
    node* c = last;
    while(n > 1){
        if(i % k == 0){
            c->killed = 1;
        }
    }
    return p->value;

}
int main()
{
    LinkedList l;
    cin >> l;
    cout << l;
    cout << l.the_last_one_left_alive(2, 10);
    return 0;
}

