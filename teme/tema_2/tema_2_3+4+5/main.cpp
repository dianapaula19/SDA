#include <iostream>

using namespace std;
typedef struct node{
    int value;
    node* next;
};
void switch_list_int(node*& head){

    int x;
    cout << "Introduceti o optiune noua: " << endl;
    cin >> x;
    while(x){
        switch(x){
            case 1:{
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
            case 2:{
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
            case 3:{
                int sum = 0, nr_elem_negative = 0, nr_elem_pozitive = 0, medie = 0;
                node* c = new node;
                c = head;
                while(c != NULL){
                    int x = c->value;
                    if(x > 0){
                        nr_elem_pozitive++;
                    }else{
                        sum+=x;
                        nr_elem_negative++;
                    }
                    c = c->next;
                }
                if(nr_elem_negative == 0){
                    cout << "Nu exista numere negative" << endl;
                    cout << nr_elem_pozitive << endl;
                }else{
                medie = sum / nr_elem_negative;
                cout << medie << " " << nr_elem_pozitive << endl;
                }
                cout << "Introduceti o optiune noua: " << endl;
                cin >> x;
            }
            break;
            case 4:{
                if(head->next != NULL){
                    node* p = new node;
                    node* c = new node;
                    c = head;
                    while(c->next != NULL){
                        p = c;
                        c = c->next;
                        int medie_aritmetica = (p->value + c->value) / 2;
                        node* q = new node;
                        q->value = medie_aritmetica;
                        p->next = q;
                        q->next = c;
                    }
                }
                cout << "Introduceti o optiune noua: " << endl;
                cin >> x;
            }
            break;
            case 5:{
                cout << "Reverse the list" << endl;
                node *p, *c, *n;
                p = new node;
                c = new node;
                n = new node;
                c = head;
                p = NULL;
                n = NULL;
                while(c != NULL){
                    n = c->next;
                    c->next = p;
                    p = c;
                    c = n;
                }
                head = p;
                cout << "Introduceti o optiune noua: " << endl;
                cin >> x;

            }
            break;

        }
    }
}
int size_of_list(node* head){

    int nr = 0;
    while(head != NULL){
        head = head->next;
        nr++;
    }
    return nr;

}
void add_at_the_end(node*& head, int x){
    node* temp = new node;
    node* q = new node;
    q->value = x;
    q->next = NULL;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = q;
    temp = q;
}
void suma(node* node1, node* node2, node*& s){

    node* temp = new node;
    temp->next = NULL;
    s = temp;
    int carry = 0;
    while(node1 != NULL && node2 != NULL){
        int number = node1->value + node2->value + carry;
        carry = number / 10;
        temp->value = number % 10;
        temp->next = new node;
        temp = temp->next;
        temp->next = NULL;
        node1 = node1->next;
        node2 = node2->next;
    }
    if(carry > 0){
        temp->value = carry;
        temp->next = new node;
        temp = temp->next;
        temp->next = NULL;
    }
    node* q = new node;
    q = s;
    while(q->next->next != NULL){
        q = q->next;
    }
    delete q->next;
    q->next = NULL;
}
int main()
{
    node* node1 = new node;
    node* node2 = new node;
    node1 = NULL;
    node2 = NULL;
    cout << "-------NODE1-------" << endl;
    switch_list_int(node1);
    cout << "-------NODE2-------" << endl;
    switch_list_int(node2);
    int n = size_of_list(node1), m = size_of_list(node2);
    if(n > m){
        for(int i = m; i < n; i++){
            add_at_the_end(node2, 0);
        }
    }else{
        for(int i = n; i < m; i++){
            add_at_the_end(node1, 0);
        }
    }
    cout << "-------SUMA--------" << endl;
    node* s;
    suma(node1, node2, s);
    switch_list_int(s);

    return 0;
}
