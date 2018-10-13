#include <vector>
#include <queue>
#include <iostream>

#define vi vector< int >
#define vii vector< vector< int > >
#define vi vector< int >
#define vii vector< vector< int > >
#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) ((c).find(all(c),x) != (c).end())

using namespace std;

int n;
int dist[1000000];
vi con[100000];

int distance (int o, int d) {
    for (int i = 0; i<n; i++) {
        dist[i] = -1;
    }

    dist[o] = 0;
    queue< int > q;
    q.push(o);
   
    while(!q.empty()) {
        fr(i, n) {
        cout << dist[i] << " ";
    } cout << ">.<" << endl;
        int u = q.front(); q.pop();
        if (u == d) {
            return dist[u];
        }
        for (int i=0; i < con[u].size(); i++) {
            int v = con[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] +1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    cin >> n;
    int v;
    cin >> v;
    fr(i,v) {
        int a,b;
        cin >> a >> b;
        con[a].pb(b);
    }
    fr(i, n) {
        cout << i << " -> ";
        fr(j, con[i].size()) {
            cout << con[i][j] << " ";
        }
        cout << endl;
    }
    cout << distance(0, 2) << endl;
    fr(i, n) {
        cout << dist[i] << " ";
    } cout << ">.<" << endl;
}