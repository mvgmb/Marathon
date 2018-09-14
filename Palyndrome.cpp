#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define fr(i, n) for (int i = 0; i < n; i++)

int main()
{
    int loop;
    cin >> loop;

    int n;
    string s;
    fr(_, loop)
    {
        cin >> n >> s;
        bool isP = true;
        fr(i, n / 2)
        {
            int r = abs(s.at(i) - s.at(n - i - 1));
            if (!(r == 2 || r == 0))
            {
                isP = false;
                break;
            }
        }
        cout << (isP ? "YES" : "NO") << endl;
    }
}