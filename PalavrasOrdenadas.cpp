#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

int main()
{
    int loop;
    cin >> loop;
    for (int i = 0; i < loop; i++)
    {
        string s = "";
        char r = 'O';

        cin >> s;
        char prev = tolower(*s.begin());
        for (string::iterator i = ++s.begin(); i != s.end(); i++)
        {
            if (prev >= tolower(*i))
            {
                r = 'N';
                break;
            }
            prev = tolower(*i);
        }

        cout << s << ": " << r << endl;
    }
}
