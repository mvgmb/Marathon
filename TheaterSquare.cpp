#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double n, m, a;
    cin >> n >> m >> a;
    long long r = ceil(n / a) * ceil(m / a);
    cout << r;
}
