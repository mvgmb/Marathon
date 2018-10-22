#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

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
    double n, l;
    cin >> n >> l;
    vi lamp;
    fr(_, n) {
        int tmp; cin >> tmp;
        lamp.pb(tmp);
    }
    
    sort(all(lamp));

    double begin = 2*(lamp[0] - 0);
    double end = 2*(l - lamp[n-1]);

    double ans = max(begin, end);
    
    for(int i = 1; i <= n; i++) {
        double tmp = lamp[i] - lamp[i-1];
        ans = max(ans, tmp);
    }
    ans /= 2;
    cout << setprecision(9) << ans;
}
