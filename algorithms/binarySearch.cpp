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

int bs(vi v, int l, int r, int x) {
    while (l <= r) {
        
        int m = (l+r)/2;
        cout << l << " " << m << " " << r << endl;

        if (v[m] == x) return m;

        if (v[m] < x) l = m+1;
        else r = m-1;
        
    }
    return -1;
}

bool f (int i, int j){
    return i-3 <= j;
}

int main() {
    int myints[] = {10,20,30,30,20,10,10,20};
    //sort(all(v));
    int n;
	cin >> n;
    vi v;
	fr(i, n) v.pb(i);
    fr(i, n) cout << v[i] << " ";
    int x;
    cin >> x;   
    
    auto min = lower_bound(all(v), x, f);//bs(test, 0, n-1, x);
    auto max = upper_bound(all(v), x, f);//bs(test, 0, n-1, x);
    
    int a = max-v.begin();
    int b = min-v.begin();

    cout << a << " " << v[a] << endl;
    cout << b << " " << v[b];

}
