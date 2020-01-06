#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main() {
    deque <int> d;
    ifstream in;
    ofstream out;
    in.open("lacoada.in");
    out.open("lacoada.out");
    int n, k;
    in >> n >> k;
    for(int i = 1; i <= n; ++i) {
        d.push_back(i);
    }
    for(int i = 0; i < k; ++i) {
        int op;
        in >> op;
        switch(op) {
            case 1: {
                d.pop_front();
            }
            break;
            case 2: {
                ++n;
                d.push_back(n);
            }
            break;
            case 3: {
                int x;
                in >> x;
                for(int i = 0; i < d.size(); ++i) {
                    if (d[i] == x) {
                        d.erase(d.begin() + i);
                        break;
                    }
                }
                d.push_front(x);
            }
            break;
        }
    }
    out << d.size() << "\n";
    for(int i = 0; i < d.size(); ++i) {
        out << d[i] << " ";
    }
    return 0;
}
