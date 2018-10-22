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
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while (n != 0) {
        int m; cin >> m;
        int u, v;
        vi con[10000];
        while(m--) {
            cin >> u >> v;
            con[u].pb(v);
            con[v].pb(u);
        }

        int color[n];
        fr(i, n) color[i] = -1;

        queue< int > q;
        q.push(u);
        color[u] = 0;
        bool isBip = true;

        while(!q.empty() && isBip) {
            int u = q.front(); q.pop();
            
            fr(i, con[u].size()) {
                int v = con[u][i];
                if (color[v] == -1) {
                    color[v] = (color[u]==0)? 1:0;
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    isBip = false;
                    break;
                }
            }
        }
                
        cout << (isBip? "":"NOT ") << "BICOLORABLE." << endl;

        cin >> n;
    }
}