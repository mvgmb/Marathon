#include <iostream>
#include <set>

using namespace std;

#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end())
#define tr(c, it) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

int main()
{
    int n;
    cin >> n;
    int a[1000];
    set< int > s;
    fr(i, n) {
        cin >> a[i];
        s.insert(a[i]);
        if (a[i] % 2 == 0) {
            s.insert(a[i]-1);
        }
        else s.insert(a[i]+1);
    }
    for(set< int >::iterator it = s.begin(); it != s.end(); it++) {
        if (*it % 2 == 0) // is even -1
        {
            fr(i, n) {
                if (a[i] == *it) a[i]--;
            }
        }
        else { // is odd +1
            fr(i, n) {
                if (a[i] == *it) a[i]++;
            }
        }
    }
    fr(i, n) {
        cout << a[i] << " ";
    }
}