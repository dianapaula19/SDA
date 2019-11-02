#include <iostream>

using namespace std;
typedef struct node{
    int value;
    node* next;
};
void switch_node(node*& head, node*& tail){

    int x;
    cout << "Introduceti o optiune noua: " << endl;
    cin >> x;
    while(x){
        switch(x){
        case 1:{
            cout << "1.A" << endl;
            cout << "Introduceti o valoare noua in lista: " << endl;
            int new_value;
            cin >> new_value;
            node* q = new node;
            q->value = new_value;
            q->next = NULL;
            if(head == NULL){
                head = q;
                tail = q;
                q = NULL;
            }else{
                tail->next = q;
                tail = q;
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
        break;
        case 2:{
            cout << "1.B" << endl;
            cout << "Introduceti o valoare noua in lista: " << endl;
            int new_value;
            cin >> new_value;
            node* q = new node;
            q->value = new_value;
            q->next = head;
            head = q;
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
        break;
        case 3:{
            cout << "1.C" << endl;
            cout << "Introduceti valoarea dupa care vreti sa adaugati elementul: " << endl;
            int value;
            cin >> value;
            cout << "Introduceti o valoare noua in lista: " << endl;
            int new_value;
            cin >> new_value;
            node* p = new node;
            p = head;
            while(p != NULL && p->value != value){
                p = p->next;
            }
            if(p == NULL){
                cout << "Nu exista valoarea in lista" << endl;
            }else{
                node* q = new node;
                q->value = new_value;
                q->next = p->next;
                p->next = q;
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 4:{
            cout << "1.D" << endl;
            cout << "Lista actuala: " << endl;
            node* c = new node;
            c = head;
            while(c != NULL){
                cout << c->value << " ";
                c = c->next;
            }
            cout << endl;
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 5:{
            // it works
            cout << "1.E" << endl;
            cout << "Introduceti valoarea cautata" << endl;
            int value;
            cin >> value;
            node* c = new node;
            c = head;
            while(c->next != NULL && c->value != value){
                c = c->next;
            }
            if(c->value == value){
                cout << "Elementul a fost gasit" << endl;
            }else{
            cout << "Elementul nu a fost gasit" << endl;
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 6:{
            // it works
            cout << "1.F" << endl;
            cout << "Cautati elementul aflat pe urmatoarea pozitie: " << endl;
            int pozitie;
            cin >> pozitie;
            cout << "Introduceti valoarea cautata" << endl;
            int value;
            cin >> value;
            int i = 0;
            node* c = new node;
            c = head;
            while(c->next != NULL && i < pozitie){
                c = c->next;
                i++;
            }
            if(c->value == value){
                cout << "Elementul a fost gasit" << endl;
            }else{
            cout << "Elementul nu a fost gasit" << endl;
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 7:{
            // it works
            cout << "1.G" << endl;
            cout << "Stergeti urmatorul element:" << endl;
            int value;
            cin >> value;
            node* c = new node;
            node* p = new node;
            c = head;
            while(c->value != value && c->next != NULL){
                p = c;
                c = c->next;
            }
            if(c->next == NULL){
                cout << "Elementul nu se afla in lista" << endl;
            }
            p->next = c->next;
            delete c;
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 8:{
            cout << "1.H" << endl;
            cout << "Stergeti elementul aflat pe urmatoarea pozitie:" << endl;
            int pozitie;
            cin >> pozitie;
            node* c = new node;
            node* p =  new node;
            c = head;
            if(pozitie == 0){
                head = c->next;
                delete c;
            }else{
            int i = 0;
            while( i < pozitie && c->next != NULL ){
                p = c;
                c = c->next;
                i++;
            }
            if( i != pozitie ){
                cout << "Nu exista niciun element pe aceasta pozitie" << endl;
            }else{
            p->next = c->next;
            delete c;
            }
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 9:{
            cout << "1.I" << endl;
            node* p = new node;
            p = head;
            while( head != NULL ){
                head = head->next;
                cout << "elementul " << p->value << " a fost sters" << endl;
                delete p;
                p = head;
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
            break;
        case 10:{
            cout << "2." << endl;
            cout << "Introduceti o valoare noua in lista: " << endl;
            int new_value;
            cin >> new_value;
            node* q = new node;
            node* c = new node;
            node* p = new node;
            q->value = new_value;
            q->next = NULL;
                if(head == NULL){
                    head = q;
                    tail = q;
                    q = NULL;
                }else{
                    c = head;
                    if(head->value > new_value){
                        q->next = head;
                        head = q;
                    }else if(tail->value < new_value){
                        tail->next = q;
                        tail = q;
                    }else{
                        while(c->next != NULL && c->value < new_value){
                            p = c;
                            c = c->next;
                        }
                        p->next = q;
                        q->next = c;
                    }
                }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
        break;
        default:{
            x = 0;
        }
        break;
    }
}
}
int main()
{
    node* head = new node;
    node* tail = new node;
    head = NULL;
    tail = NULL;
    switch_node(head, tail);
    return 0;
}

