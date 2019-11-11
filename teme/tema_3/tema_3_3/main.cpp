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

    if(top != NULL){
        return top->data;
    }else{
        return '\0';
    }

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
void expresie_corect_parantezata(Stack& s){

    string x;
    cin >> x;
    while(x == "ok"){
        cout << "expresie" << endl;
        string exp;
        cin >> exp;
        int nope = 0;
        int i = 0;
        while(exp[i] != '\0'){
            if(exp[i] == '('){
                s.push(exp[i]);
            }else if(exp[i] == ')'){
                if(s.peek() != '('){
                    s.push(exp[i]);
                    break;
                }else{
                    if(s.empty() == 0){
                    s.pop();
                    }else{
                    nope = 1;
                    break;
                    }
                }
            }
            ++i;
        }
        if(s.empty() == 1 && nope == 0){
            cout << "corect parantezata" << endl;
        }else{
            cout << i << endl;
            cout << "nu este corect parantezata" << endl;
        }
        cin >> x;
        }



}
int main()
{
    Stack s;
    expresie_corect_parantezata(s);
    return 0;
}
