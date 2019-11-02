#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

struct node{

    char data;
    node* next;

};
class Stack{

    private:
        node* top;
    public:
        Stack();
        void push(char);
        void pop();
        char peek();
        bool empty();
        int search(char);
        void afisare();

};
Stack::Stack(){

    top = NULL;

}
void Stack::push(char c){

    node* temp = new node;
    temp->data = c;
    temp->next = top;
    top = temp;

}
void Stack::pop(){

    if(top != NULL){
    node* temp = top;
    top = top->next;
    delete temp;
    }

}
char Stack::peek(){

    return top->data;

}
bool Stack::empty(){

    if(top == NULL){
        return true;
    }else{
        return false;
    }
}
int Stack::search(char a){

    int distance = 0;
    node* temp = top;
    while(temp != NULL && temp->data != a){
        temp = temp->next;
        distance++;
    }
    if(temp != NULL){
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
            s.pop();
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 3:{
            cout << "peek" << endl;
            cout << s.peek() << endl;
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
        case 7:{

            cout << "expresie" << endl;
            string exp;
            cin >> exp;
            int i = 0;
            while(exp[i] != '\0'){
                if(exp[i] == '('){
                    s.push(exp[i]);
                }else if(exp[i] == ')'){
                    if(s.peek() != '('){
                        cout << s.search('(') << endl;
                        break;
                    }else{
                        s.pop();
                    }
                }
                i++;
            }
            if(s.empty() == 1){
                cout << "corect parantezata" << endl;
            }else{
                cout << "nu este corect parantezata" << endl;
            }
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
