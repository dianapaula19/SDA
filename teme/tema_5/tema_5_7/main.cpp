#include <iostream>

using std::cout;

int a[] = {1, 2, 3, 4, 5, 6, 5,  4, 3, 2, 1};
int n = sizeof(a) / sizeof(a[0]);

void bitonicSort() {
    cout << "BEFORE SORT\n";
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    int i = 0;
    int j = n - 1;
    int* b = new int [n];
    int k = 0;
    while ((a[i] < a[i + 1]) && (a[j] < a[j - 1])) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            ++i;
        } else {
            b[k] = a[j];
            --j;
        }

        ++k;
    }
    while (a[i] < a[i + 1]) {
        b[k] = a[i];
        ++i;
        ++k;
    }
    while (a[j] < a[j - 1]) {
        b[k] = a[j];
        --j;
        ++k;
    }
    b[k] = a[j];
    ++k;
    cout << "AFTER SORT\n";
    for(int i = 0; i < k; ++i) {
        cout << b[i] << " ";
    }
    delete [] b;
}

int main()
{
    bitonicSort();
    return 0;
}
