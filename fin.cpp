#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int main()
{
    int n;
    string s, t;
    vector<int> v;
    cin >> n >> s >> t;
    int r = 0;
    if (s != t){
        tr(s, sit) {
            int steps = 0;
            tr(t, tit) {
                if (*sit == *tit) {
                    t.erase(tit);
                    r += steps;
                    if (steps != 0) v.push_back(steps);
                    break;
                }
                else {
                    steps++;
                }
            }
        }
    }

    cout << (r > 10000 ? -1 : r);
    if (r <= 10000) {
        cout << endl;
        tr(v, it) {
            cout << *it << " ";
        }
    }
}