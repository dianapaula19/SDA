#include <iostream>
#include <vector>

using std::swap;
using std::vector;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

class MaxHeap {

public:
    vector <int> a;
    friend istream& operator >> (istream&, MaxHeap&);
    friend ostream& operator << (ostream&, const MaxHeap&);
    void insert_new_value(int);
    void heapify(int, int);
    void deleteRoot();
    void heapSort();

};
istream& operator >> (istream& in, MaxHeap& heap) {

    cout << "Numarul de elemente este pe care vreti sa-l adaugati in heap este:  ";
    int n;
    in >> n;
    for(int i = 0; i < n; ++i) {
        cout << "element nou = ";
        int new_value;
        cin >> new_value;
        heap.insert_new_value(new_value);
    }
    return in;

}
ostream& operator << (ostream& out, const MaxHeap& heap) {

    for(auto i : heap.a) {
        out << i << " ";
    }
    out << "\n";
    return out;
}
void MaxHeap::insert_new_value(int new_value) {

    if (a.size() == 0) {
        a.push_back(new_value);
    } else {
        a.push_back(new_value);
        for(int i = a.size() / 2 - 1; i >= 0; --i) {
            heapify(a.size(), i);
        }
    }

}
void MaxHeap::heapify(int n, int i) {

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int largest = i;
    if (left < n && a[largest] < a[left]) {
        largest = left;
    }
    if (right < n && a[largest] < a[right]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(n, largest);
    }

}
void MaxHeap::deleteRoot() {

    int size_heap = a.size();
    swap(a[0], a[size_heap - 1]);
    a.pop_back();
    --size_heap;
    for(int i = size_heap / 2 - 1; i >= 0; --i) {
        this->heapify(size_heap, i);
    }

}
void MaxHeap::heapSort() {

    int size_heap = a.size();
    for(int i = size_heap - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        heapify(i, 0);
    }

}
void print_options() {
    cout << "1-adaugati n elemente\n";
    cout << "2-adaugati un element\n";
    cout << "3-stergeti radacina\n";
    cout << "4-heapSort\n";
    cout << "5-afisati heap-ul\n";
}
void menu(MaxHeap& max_heap) {

    print_options();
    int op;
    cout << "optiunea = ";
    cin >> op;
    while(op) {
        switch(op) {
            case 1: {
                cin >> max_heap;
                print_options();
                cout << "optiunea = ";
                cin >> op;
            }
            break;
            case 2: {
                cout << "element nou = ";
                int new_value;
                cin >> new_value;
                max_heap.insert_new_value(new_value);
                print_options();
                cout << "optiunea = ";
                cin >> op;
            }
            break;
            case 3: {
                max_heap.deleteRoot();
                print_options();
                cout << "optiunea = ";
                cin >> op;
            }
            break;
            case 4: {
                max_heap.heapSort();
                cout << max_heap;
                for(int i = max_heap.a.size() / 2 - 1; i >= 0; --i) {
                    max_heap.heapify(max_heap.a.size(), i);
                }
                print_options();
                cout << "optiunea = ";
                cin >> op;
            }
            break;
            case 5: {
                cout << max_heap;
                print_options();
                cout << "optiunea = ";
                cin >> op;
            }
            break;
        }
    }
}
int main()
{
    MaxHeap max_heap;
    menu(max_heap);
    return 0;
}
