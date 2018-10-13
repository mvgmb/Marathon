#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <set>
#include <map>

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

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);    
    int n, m, z;
    int u, v, w;

    cin >> n >> m;
    map<string, int> dic;

    int dist[n][n]; 
	fr(i, n) {
        fr(j, n) {
            dist[i][j] = INF * (i != j); // THIS is the cool one
        }
    }
   
    dic.clear(); z = 0;
    while (m--) {
        string s, t;
		cin >> s >> t;
		if(!dic.count(s)) dic[s] = z++;
		if(!dic.count(t)) dic[t] = z++;
		u = dic[s]; v = dic[t];
		dist[u][v] = 1; // entraria o peso aq
		dist[v][u] = 1; // entraria o peso aq
    }

    fr(k, n) {
        fr(i, n) {
            fr(j, n) { 
	            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Just to vizualize
    fr(i, n) {
        fr(j, n) cout << dist[i][j] << " ";
        cout << endl;
    }
}