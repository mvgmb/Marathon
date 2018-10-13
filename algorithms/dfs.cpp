#include <vector>
#include <queue>
#include <iostream>

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
int vis[1000000];
vi con[100000];

int dfs (int u) {
    vis[u] = 1;
    fr(i, n) {
        cout << vis[i] << " ";
    }cout << endl;
    for(int i = 0; i< con[u].size(); i++) {
        int v = con[u][i];

        if(vis[v] == 0){
            dfs(v);
        }
    }
    return 0;   
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        vis[i] = 0;
    }
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
    dfs(0);
    fr(i, n) {
        cout << vis[i] << " ";
    }

}