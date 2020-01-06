#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

bool zeros(vector <int> a) {
    int size = a.size();
    for(int i = 0; i < size; ++i) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;

}
int main()
{
    ifstream in;
    ofstream out;
    in.open("roata.in");
    out.open("roata.out");
    int n, p;
    long suma = 0;
    int* c;
    in >> n;
    in >> p;
    c = new int [p];
    for(int i = 0; i < p; ++i) {
        in >> c[i];
        suma += c[i];
    }
    out << suma << "\n";
    vector <int> roata;
    vector <int> roata_backup;
    deque <int> coada;
    for(int i = 0; i < n; ++i) {
        roata.push_back(c[i]);
        roata_backup.push_back(c[i]);
    }
    for(int i = n; i < p; ++i) {
        coada.push_back(c[i]);
    }
    while(coada.empty() == false) {
        int min_elem = *min_element(roata.begin(), roata.end());

        for(int i = 0; i < n; ++i) {
            roata[i] -=  min_elem;
        }
        for(int i = 0; i < n; ++i) {
            if (roata[i] == 0) {
                for(int j = 0; j < p; ++j) {
                    if (roata_backup[i] == c[j]) {
                        out << j + 1 << " ";
                        c[j] = 0;
                    }
                }
                roata[i] = coada.front();
                roata_backup[i] = coada.front();
                coada.pop_front();
                break;
            }
        }
    }
    int max_elem = *max_element(roata.begin(), roata.end());
    int pos = 0;
    for(int i = 0; i < n; ++i) {
        if (roata[i] == max_elem) {
            pos = i + 1;
            break;
        }
    }
    while(zeros(roata) == false) {
        int min_elem = 1000001;

        for(int i = 0; i < n; ++i) {
            if (roata[i] != 0 && min_elem > roata[i]) {
                min_elem = roata[i];
            }
        }

        for(int i = 0; i < n; ++i) {
            if (roata[i] != 0) {
                roata[i] -=  min_elem;
            }
        }
        for(int i = 0; i < n; ++i) {
            if (roata[i] == 0) {
                for(int j = 0; j < p; ++j) {
                    if (roata_backup[i] == c[j]) {
                        out << j + 1 << " ";
                        c[j] = 0;
                    }
                }
            }
        }
    }
    out << "\n" << pos;
    return 0;
}
