#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define vi vector< int >
#define vii vector< vi >
#define fr(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(),v.end())
#define pb push_back
#define tr(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define rtr(c, it) for (auto it = (c).rbegin(); it != (c).rend(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) ((c).find(all(c),x) != (c).end())

void connect(vii &c, int a, int b) {
    c[a].push_back(b);
}

void list(vii &c, int a) {
    printf("%d -> ", a);
    for (int i = 0; i < c[a].size(); i++){
        printf("%d ", c[a][i]);
    }
}

int main() {
    vi a;
    vii con;

    vi tmp;
    for (int i = 0; i<10; i++){
        tmp.push_back(i);
    }

    int i = 0;
    if (con.size() < i +1)
        con.resize(i+1);
    a.pb(0);
    con[0].emplace_back(2);
    cout << con[0][0] << " " << a[0] << endl;
    
    //con[0] = {0, 1};
    //cout << con[0][0];
    //list(con, 0);

}
