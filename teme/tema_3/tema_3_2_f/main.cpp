#include <iostream>

using namespace std;
struct node{

    int value, killed;
    node* next;

};
class LinkedList{

private:
    node *head;
public:
    int n;
    LinkedList();
    void AddElement(int);
    friend ostream& operator << (ostream&, const LinkedList&);
    friend istream& operator >> (istream&, LinkedList&);
    int the_last_one_left_alive(int, int);

};

LinkedList::LinkedList(){

    head = NULL;
    n = 0;

}
istream& operator >> (istream& in, LinkedList& l){

    cout << "New List" << endl;
    int n;
    cin >> n;
    l.n = n;
    for(int i = n; i >= 1; i--){
        l.AddElement(i);
    }

    return in;

}
ostream& operator << (ostream& out, const LinkedList& l){

    node* p = l.head;
    while(p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;

    return out;

}
void LinkedList::AddElement(int new_value){

    node* q = new node;
    q->value = new_value;
    q->killed = 0;
    q->next = NULL;
    if(head == NULL){
        head = q;
        q = NULL;
    }else{
        q->next = head;
        head = q;
    }

}

int LinkedList::the_last_one_left_alive(int k, int n){

    int i = 0;
    while(true){
        node* p = head;
        while(p){
            if(p->killed == 0){
            i++;
            }
            if(i % k == 0){
                p->killed = 1;
            }
            p = p->next;
        }
        node* c = head;
        int kills = n;
        while(c){
            if(c->killed == 1){
                kills--;
            }
            c = c->next;
        }
        if(kills == 1){
            break;
        }

    }
    node* p = head;
    while(p){
        if(p->killed == 0){
            return p->value;
        }
        p = p->next;
    }
    return 0;

}
int main()
{
    LinkedList l;
    cin >> l;
    int k;
    cin >> k;
    cout << l.the_last_one_left_alive(k, l.n);
    return 0;
}

