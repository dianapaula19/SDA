#include <iostream>
#include <cstring>
#include <sstream>
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
            cout << s.pop() << endl;
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

            cout << "expresie postfix" << endl;
            string element;
            cin >> element;
            while(element != "end"){
                stringstream ss(element);
                int x;
                char c;
                if(element[0] >= '0' && element[0] <= '9'){
                    ss >> x;
                    s.push(x);
                }else{
                    ss >> c;
                    int val1 = s.pop();
                    int val2 = s.pop();
                    if(c == '*'){
                        s.push(val2 * val1);
                    }else if(c == '-'){
                        s.push(val2 - val1);
                    }else if(c == '+'){
                        s.push(val2 + val1);
                    }else if(c == '/'){
                        s.push(val2 / val1);
                    }
                }

                cin >> element;
            }
            cout << s.peek() << endl;
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
