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
void Stack::push(char a){

    node* temp = new node;
    temp->data = a;
    temp->next = top;
    top = temp;

}
void Stack::pop(){

    if(top != NULL){
    node* temp = top;
    top = top->next;
    delete temp;
    }else{
        return;
    }

}
char Stack::peek(){

    if(top == NULL){
        return '\0';
    }
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
void sir_de_caractere(Stack& s){

    string x;
    cin >> x;
    while(x == "ok"){
        cout << "sir de caractere" << endl;
        string sir;
        cin >> sir;
        int i = 0;
        while(sir[i] != '\0'){
            if(sir[i] == 'a'){
                if(s.peek() == 'b'){
                    s.pop();
                }else{
                    s.push('a');
                }
            }else if(sir[i] == 'b'){
                if(s.peek() == 'a'){
                    s.pop();
                }else{
                    s.push('b');
                }
            }
                i++;
        }
        if(s.empty() == 1){
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
        cin >> x;
        }

}
int main()
{
    Stack s;
    sir_de_caractere(s);
    return 0;
}
