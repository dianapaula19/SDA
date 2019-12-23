#include <iostream>

using std::cout;
using std::swap;

int v[] = {9, 10, 15, 3, 2, 5, 1, 1, 1, 2, 3, 24, 25, 1, 7, 10};
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
int partition(int left, int right) {

    int last = right;
    --right;
    while(left <= right) {
        if (v[left] < v[last]) {
            ++left;
        } else {
            swap(v[left], v[right]);
            right--;
        }
    }
    swap(v[left], v[last]);
    return left;

}
void quickSort(int left, int right) {

    if(left < right) {
        if (right - left < 12) {
            insertionSort(left, right);
        } else {
            int p = partition(left, right);
            quickSort(left, p - 1);
            quickSort(p + 1, right);
        }
    }

}
int main()
{
    printArray();
    quickSort(0, n - 1);
    printArray();
    return 0;
}
