#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::swap;

int v[] = {4, 5, 2, 3, 1, 9, 10, 15, 2, 6, 7, 21};
int n = sizeof(v) / sizeof(v[0]);

void printArray() {

    for(int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";

}

int partitionRandom(int left, int right) {

    srand(time(nullptr));
    int r = left + (rand() % (right - left));
    cout << "pivotul ales este: " << r << "\n";
    int last = right;
    swap(v[r], v[right]);
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
        int p = partitionRandom(left, right);
        quickSort(left, p - 1);
        quickSort(p + 1, right);
    }

}
int main()
{
    printArray();
    quickSort(0, n - 1);
    printArray();
    return 0;
}
