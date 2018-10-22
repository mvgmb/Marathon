#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <set>
#include <map>
#include <algorithm>

#define vi vector<int>
#define vii vector<vector<int>>
#define ii pair<int, int>
#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) ((c).find(all(c), x) != (c).end())

using namespace std;

int main() {
    string s;
    cin >> s;

    map< char, vi > o;
    for(int i = 0; i < s.length(); i++) {
        o[s[i]].push_back(i);
    }

    int ans = s.length();
    tr(o, it){
        it->second.push_back(s.length()); // consider end
        int tmp = 0;
        int last = -1; // consider begin
        tr(it->second, i) {
            tmp = max(tmp, (*i-1) - last);
            last = *i;
        }    
        ans = min(ans, tmp);
    }
    cout << ans+1;
}
