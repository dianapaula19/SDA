#include <iostream>
#include <math.h>
using namespace std;
int last_one_left_alive(int n, int k) {

    int res = 0;
    for (int i = 1; i <= n; i++)
      res = (res + k) % i;
    return res + 1;

}
int main()
{
    double n = pow(2, 100) + 6;
    cout << last_one_left_alive(n, 2) << endl;
    return 0;
}
