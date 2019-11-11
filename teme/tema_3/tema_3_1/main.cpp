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
        int pop();
        int peek();
        bool empty();
        int search(int);
        void afisare();

};
Stack::Stack(){

    top = NULL;

}
void Stack::push(int a){

    node* temp = new node;
    temp->data = a;
    temp->next = top;
    top = temp;

}
int Stack::pop(){

    int x = top->data;
    node* temp = top;
    top = top->next;
    delete temp;
    return x;

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
void Stack::afisare(){

    node* temp = top;
    while(temp){
        cout << temp->data << endl;
        temp = temp->next;
    }

}
void menu(Stack& s){

    cout << "Introduceti o optiune noua:" << endl;
    int x;
    cin >> x;
    while(x){
        switch(x){

        case 1:{
            cout << "push" << endl;
            int a;
            cin >> a;
            s.push(a);
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 2:{
            cout << "pop" << endl;
            if(s.empty() == 0){
            cout << s.pop() << endl;
            }else{
            cout << "Nu exista elemente in stiva" << endl;
            }
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 3:{
            cout << "peek" << endl;
            if(s.empty() == 0){
            cout << s.peek() << endl;
            }else{
            cout << "Nu exista elemente in stiva" << endl;
            }
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 4:{
            cout << "empty" << endl;
            cout << s.empty() << endl;
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 5:{
            cout << "search" << endl;
            cout << "Elementul cautat" << endl;
            int a;
            cin >> a;
            cout << s.search(a) << endl;
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 6:{
            cout << "afisare" << endl;
            s.afisare();
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        }
    }

}
int main()
{
    Stack s;
    menu(s);
    return 0;
}
