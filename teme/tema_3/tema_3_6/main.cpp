#include <iostream>

using namespace std;
struct node{
    int data;
    node* next;
};
class Queue{
private:
    node *front, *rear;
public:
    Queue();
    void push(int);
    int pop();
    int peek();
    bool empty();
    int search(int);
    void afisare();

};
Queue::Queue(){

    front = NULL;
    rear = NULL;

}
void Queue::push(int a){

    node* temp = new node;
    temp->data = a;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
        rear = temp;
    }else{
        rear->next = temp;
        rear = temp;
    }

}
int Queue::pop(){

    int x = front->data;
    node* temp = front;
    front = front->next;
    delete temp;
    return x;

}
int Queue::peek(){

    return front->data;

}
bool Queue::empty(){

    if(front == NULL){
        return true;
    }else{
        return false;
    }
}
int Queue::search(int a){

    int distance = 0;
    node* temp = front;
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
void Queue::afisare(){

    node* temp = front;
    while(temp){
        cout << temp->data << endl;
        temp = temp->next;
    }

}
void menu(Queue& q){

    cout << "Introduceti o optiune noua:" << endl;
    int x;
    cin >> x;
    while(x){
        switch(x){

        case 1:{
            cout << "push" << endl;
            int a;
            cin >> a;
            q.push(a);
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 2:{
            cout << "pop" << endl;
            if(q.empty() == 0){
            cout << q.pop() << endl;
            }else{
            cout << "nu exista elemente in lista" << endl;
            }
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 3:{
            cout << "peek" << endl;
            if(q.empty() == 0){
            cout << q.peek() << endl;
            }else{
            cout << "nu exista elemente in coada" << endl;
            }
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 4:{
            cout << "empty" << endl;
            cout << q.empty() << endl;
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 5:{
            cout << "search" << endl;
            cout << "Elementul cautat" << endl;
            int a;
            cin >> a;
            cout << q.search(a) << endl;
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        case 6:{
            cout << "afisare" << endl;
            q.afisare();
            cout << "Introduceti o optiune noua:" << endl;
            cin >> x;
        }
        break;
        }
    }

}
int main()
{
    Queue q;
    menu(q);
    return 0;
}
