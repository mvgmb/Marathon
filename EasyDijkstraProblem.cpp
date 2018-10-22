#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <set>


#define vi vector< int >
#define vii vector< vector< int > >
#define ii pair< int, int >
#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end())
#define pb push_back
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) ((c).find(all(c),x) != (c).end())

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int loop;
    cin>>loop;
    
    fr(_,loop) {
        vector< ii > con[10000];
        vi dist(10000, INF);
        int parent[10000];
        priority_queue< ii, vector< ii >, greater< ii > > pq;

        int n, m, s, t;
        int u, v, w;

        set< int > st;

        cin >> n >> m; 
        
        while(m--) {
            cin >> u >> v >> w;
            con[u].push_back({v,w});
            con[v].push_back({u,w});
        }

        cin >> s >> t;

        dist[s] = 0;
        pq.push(ii(0,s));
            
        while(!pq.empty()) {
            ii front = pq.top(); pq.pop();
            
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (auto v : con[u]) {
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                    parent[v.first] = u;
                }
            } 
        }
        
        if (dist[t] == INF) cout << "NO" << endl;
        else cout << dist[t] << endl;
    
    }
}