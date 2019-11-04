#include <iostream>

using namespace std;
struct node{

    int data;
    node* next;

};
class Stack{

    private:
        node* top;
    public:
        Stack();
        void push(int);
        void pop();
        int peek();
        bool empty();
        int search(int);
        void valid();
        friend ostream& operator << (ostream&, const Stack&);


};
ostream& operator << (ostream& out, const Stack& s){

    node* p = s.top;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return out;

}
Stack::Stack(){

    top = NULL;

}
void Stack::push(int a){

    node* temp = new node;
    temp->data = a;
    temp->next = NULL;
    if(temp == NULL){
        top = temp;
    }else{
        temp->next = top;
        top = temp;
    }

}
void Stack::pop(){

    node* temp = top;
    top = top->next;
    delete temp;

}
int Stack::peek(){

    return top->data;

}
bool Stack::empty(){

    if(top == NULL){
        return true;
    }else{
        return false;
    }
}
int Stack::search(int a){

    int distance = 0;
    node* temp = top;
    while(temp != NULL && temp->data != a){
        temp = temp->next;
        distance++;
    }
    if(temp->data == a){
        return distance;
    }else{
        return -1;
    }

}
void Stack::valid(){

    cout << "Numarul de elemente: " << endl;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(this->empty() == 0 && this->peek() == x){
            this->pop();
        }else{
            this->push(x);
        }
    }
    if(this->empty() == 1){
        cout << "Exista o configuratie valida";
    }else{
        cout << "Nu exista o configuratie valida";
    }

}
int main()
{
    Stack s;
    s.valid();
    return 0;
}
