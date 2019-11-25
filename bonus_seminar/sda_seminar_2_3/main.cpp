#include <iostream>
#include <math.h>

using namespace std;
struct element{

    int value;
    int position;

};
int max_digit_number(int n, element* e){

    int maximum = -1;
    for(int i = 0; i < n; i++){
        if(maximum < e[i].value){
            maximum = e[i].value;
        }
    }
    int num_digits = 0;
    while(maximum > 0){
        num_digits++;
        maximum = maximum / 10;
    }
    return num_digits;

}
void sort_numbers(int n, element *&e, int which_digit){

    int p = pow(10, which_digit);
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){

            int digit_i;
            int digit_j;
            int dont_swap_i = 0;
            int dont_swap_j = 0;
            if(e[i].value < p){
                digit_i = 0;
                dont_swap_i = 1;
            }else{
                digit_i = (e[i].value / p) % 10;
            }
            if(e[j].value < p){
                digit_j = 0;
                dont_swap_i = 1;
            }else{
                digit_j = (e[j].value / p) % 10;
            }

            if(digit_i > digit_j){
                swap(e[i].value, e[j].value);
            }else if(digit_i == digit_j){
                if(e[i].position > e[j].position){
                if(dont_swap_i == 0 && dont_swap_j == 0){
                swap(e[i].value, e[j].value);
                }

            }
            }
        }
    }
}
void print_array(int n, element* e, int which_digit){

    cout << "Pasul " << which_digit + 1 << endl;
    for(int i = 0; i < n; i++){
        cout << e[i].value << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        e[i].position = i;
    }
    cout << endl;

}

int main()
{
    cout << "Number of elements = ";
    int n;
    cin >> n;
    element* e = new element [n];
    for(int i = 0; i < n; i++){
        cin >> e[i].value;
        e[i].position = i;
    }
    for(int i = 0; i < max_digit_number(n, e); i++){
        sort_numbers(n, e, i);
        print_array(n, e, i);
    }
    return 0;
}
