#include <iostream>
#include <vector>


using namespace std;

#define vi vector< int >
#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) ((c).find(all(c),x) != (c).end())

void dfs(){
    
}

int main() {
    int loop;
    cin >> loop;
    int color[200];
    vi con[10000];

    fr(_, loop) {
        int v, e;
        cin >> v >> e;
        fr(i, v) {
            color[i] = -1;
        }
        fr(i, e){
            con[i].clear();
        }
        fr(i,e){
            int a,b;
            cin >> a >> b;
            con[a].pb(b);

        }
    }
}