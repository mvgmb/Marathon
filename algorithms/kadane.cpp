//Max Subarray Sum O(N)
#include <iostream>

using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int a[n+1];
    int c_max[n+1];

    c_max[0] = 0;
    int ans = -(0x3f3f3f3f);
    
    for(int i = 1; i<=n; i++) {
        cin >> a[i];
        c_max[i] = max(a[i], c_max[i-1] + a[i]);
        ans = max(ans, c_max[i]);
    }
    cout << ans << endl;

}