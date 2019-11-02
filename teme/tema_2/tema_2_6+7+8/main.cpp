#include <iostream>
#include <math.h>
using namespace std;
typedef struct polinom{
    int gr, coef;
    polinom* next;
};
void switch_polinom(polinom*& head, polinom*& tail){
    int x;
    cout << "Introduceti o optiune noua: " << endl;
    cin >> x;
    while(x){
        switch(x){
        case 1:{
            cout << "Introduceti o valoare noua in lista: " << endl;
            int new_gr, new_coef;
            cin >> new_gr >> new_coef;
            polinom* q = new polinom;
            polinom* c = new polinom;
            polinom* p = new polinom;
            q->gr = new_gr;
            q->coef = new_coef;
            q->next = NULL;
            if(head == NULL){
                    head = q;
                    tail = q;
                    q = NULL;
                }else{
                    c = head;
                    if(head->gr < new_gr){
                        q->next = head;
                        head = q;
                    }else if(tail->gr > new_gr){
                        tail->next = q;
                        tail = q;
                    }else{
                        while(c->next != NULL && c->gr > new_gr){
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
        case 2:{
            polinom* c = new polinom;
            c = head;
            while(c != NULL){
                if(c->gr > 0){
                if(c->next != NULL){
                    cout << c->coef << "*X^" << c->gr << " + ";
                }else{
                    cout << c->coef << "*X^" << c->gr;
                }
                }else{
                if(c->next != NULL){
                    cout << c->coef << " + ";
                }else{
                    cout << c->coef;
                    }
                    }
                    c = c->next;
                }
                cout << endl;
                cout << "Introduceti o optiune noua: " << endl;
                cin >> x;
            }
        break;
        case 3:{
            cout << "6." << endl;
            cout << "a = ";
            int a;
            cin >> a;
            polinom* p = new polinom;
            p = head;
            while(p != NULL){
                p->coef = p->coef * a;
                p = p->next;
            }
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
        break;
        case 4:{
            cout << "7." << endl;
            cout << "x = ";
            int punct;
            cin >> punct;
            int value = 0;
            polinom* p = new polinom;
            p = head;
            while(p != NULL){
            value+= pow(punct, p->gr) * p->coef;
            p = p->next;
            }
            cout << value << endl;
            cout << "Introduceti o optiune noua: " << endl;
            cin >> x;
        }
        break;
        default:
            x = 0;
    }
}
}
void sum(polinom* p, polinom* q, polinom*& s){
    polinom* temp = new polinom;
    temp->next = NULL;
    s = temp;
    while(p != NULL && q != NULL){
        if(p->gr == q->gr){
            temp->coef = p->coef + q->coef;
            temp->gr = p->gr;
            p = p->next;
            q = q->next;
        }else if(p->gr > q->gr){
            temp->coef = p->coef;
            temp->gr = p->gr;
            p = p->next;
        }else{
            temp->coef = q->coef;
            temp->gr = q->gr;
            q = q->next;
        }
        temp->next = new polinom;
        temp = temp->next;
        temp->next = NULL;
    }
    while(p != NULL || q != NULL){

        if(p != NULL){
            temp->coef = p->coef;
            temp->gr = p->gr;
            p = p->next;
        }
        if(q != NULL){
            temp->coef = q->coef;
            temp->gr = q->gr;
            q = q->next;
        }
        temp->next = new polinom;
        temp = temp->next;
        temp->next = NULL;
    }
    polinom* c = new polinom;
    c = s;
    while(c->next->next != NULL){
        c = c->next;
    }
    delete c->next;
    c->next = NULL;
}
void print_polinom(polinom* c){

    while(c != NULL){
        if(c->gr > 0){
            if(c->next != NULL){
                cout << c->coef << "*X^" << c->gr << " + ";
            }else{
                cout << c->coef << "*X^" << c->gr;
            }
            }else{
            if(c->next != NULL){
                cout << c->coef << " + ";
            }else{
                cout << c->coef;
                }
            }
            c = c->next;
    }
    cout << endl;

}
int main()
{
    polinom* head1 = new polinom;
    polinom* tail1 = new polinom;
    head1 = NULL;
    tail1 = NULL;
    polinom* head2 = new polinom;
    polinom* tail2 = new polinom;
    head2 = NULL;
    tail2 = NULL;
    polinom* s = new polinom;
    cout << "--------POLINOM1--------" << endl;
    switch_polinom(head1, tail1);
    cout << "--------POLINOM2--------" << endl;
    switch_polinom(head2, tail2);
    cout << "----------SUMA----------" << endl;
    sum(head1, head2, s);
    print_polinom(s);
    return 0;
}
