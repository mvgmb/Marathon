#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end())
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)

int main()
{
    int loop;
    cin >> loop;
    vector<int> v;
    fr(_, loop)
    {
        int cubes;
        cin >> cubes;
        fr(i, cubes)
        {
            if (i == v.size())
                v.push_back(1);
            else
            {
                v[i]++;
            }
        }
    }
    vector<int> ans;
    tr(v, it)
    {
        fr(i, *it)
        {
            if (i == ans.size())
                ans.push_back(1);
            else
            {
                ans[i]++;
            }
        }
    }
    rtr(ans, it)
    {
        cout << *it << " ";
    }
}