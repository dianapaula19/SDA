#include <iostream>

using namespace std;
struct node{
    int data;
    node* next;
};
class Queue{
public:
    node *front, *rear;
public:
    Queue();
    void push(int);
    void pop();
    int peek();
    bool empty();
    int search(int);
    void strategy();
    friend ostream& operator << (ostream&, const Queue&);
    friend istream& operator >> (istream&, Queue&);

};
Queue::Queue(){

    front = NULL;
    rear = NULL;

}
ostream& operator << (ostream& out, const Queue& q){

    node* p = q.front;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return out;

}
istream& operator >> (istream& in, Queue& q){

    cout << "Number of elements: " << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int new_data;
        cin >> new_data;
        q.push(new_data);
    }
    return in;

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
void Queue::pop(){

    if(front == NULL){
        return;
    }
    node* temp = front;
    front = front->next;
    delete temp;

}
int Queue::peek(){

    if(front == NULL){
        return 0;
    }
    return front->data;

}
bool Queue::empty(){

    if(front == NULL && rear == NULL){
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
void Queue::strategy(){

    Queue q;
    cout << "Numarul de linii de depozitare:" << endl;
    int k;
    cin >> k;
    cout << "Numarul de trenuri:" << endl;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        this->push(x);
    }
    Queue queues[k + 1];
    for(int i = 1; i <= k; i++){
        cout << "Trenul " << this->peek() << " se afla pe linia de depozitare " << i << endl;
        queues[i].push(this->peek());
        this->pop();
    }
    node* p = front;
    int conditie = 0;
    while(p){
        if(p->data == 0){
            conditie = 0;
            break;
        }
        if(p->data == n){
            cout << "Trenul " << p->data <<" se afla pe linia de iesire" << endl;
            n--;
            q.push(p->data);
            this->pop();
        }else{
            int ok = 0;
            for(int i = 1; i <= k; i++){
               if(queues[i].empty() == 0 && queues[i].rear->data > p->data){
                    cout << "Trenul " << p->data << " se afla pe linia de depozitare " << i << endl;
                    queues[i].push(p->data);
                    ok = 1;
                    break;
               }
            }
            if(ok == 0){
                cout << "NOPE" << endl;
                conditie = 1;
                break;
                }
            }

        p = p->next;
    }
        if(conditie == 0){
            for(int i = 1; i <= k; i++){
            cout << "Linia de depozitare " << i << endl;
            cout << queues[i];
            }
            while(n > 1){
                int i = 1;
                while(i <= k){

                    while(queues[i].empty() == 0 && queues[i].peek() == n){
                        cout << "Trenul " << queues[i].peek() <<" se afla pe linia de iesire" << endl;
                        q.push(queues[i].peek());
                        n--;
                        queues[i].pop();
                    }
                    i++;
                }
            }
        }

}
int main()
{
    Queue q;
    q.strategy();
    return 0;
}
