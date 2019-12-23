#include <iostream>

using namespace std;
int v[] = {9, 2, 4, 5, 8, 10, 14, 2, 1, 4, 89, 24, 4, 6};
int n = sizeof(v) / sizeof(v[0]);

void printArray() {

    for(int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";

}
void insertionSort(int left, int right) {

    for(int i = left + 1; i <= right; ++i) {
        int value = v[i];
        int j = i;
        while(j > left && v[j - 1] > value) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = value;
    }
}
void Merge(int left, int middle, int right) {

    int n_left = middle - left + 1;
    int n_right = right - middle;
    int *l, *r;
    l = new int [n_left];
    r = new int [n_right];
    for(int i = 0; i < n_left; ++i) {
        l[i] = v[left + i];
    }
    for(int j = 0; j < n_right; ++j) {
        r[j] = v[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n_left && j < n_right) {
        if (l[i] <= r[j]) {
            v[k] = l[i];
            ++i;
        } else {
            v[k] = r[j];
            ++j;
        }
        ++k;
    }
    while (i < n_left) {
        v[k] = l[i];
        ++k;
        ++i;
    }
    while (j < n_right) {
        v[k] = r[j];
        ++k;
        ++j;
    }
    delete [] l;
    delete [] r;

}
void mergeSort(int left, int right) {

    if (left < right) {
        if (right - left < 10) {
            insertionSort(left, right);
        } else {
            int middle = (left + right) / 2;
            mergeSort(left, middle);
            mergeSort(middle + 1, right);
            Merge(left, middle, right);
        }
    }

}

int main()
{
    printArray();
    mergeSort(0, n - 1);
    printArray();
    return 0;
}
