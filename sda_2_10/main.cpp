#include <iostream>

using namespace std;

int main()
{
    bool a = false;
    bool b = true;
    bool c = false;
    bool d = false;
    cout << ((a|b)&c)->~d;
    return 0;
}
