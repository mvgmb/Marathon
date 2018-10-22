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
    int n;
	cin >> n;
	int a[n], b[n], c[n], d[n];
	fr(i, n) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	int x[n*n], y[n*n];
	fr(i,n) 
		fr(j,n) {
			x[i*n+j] = a[i] + b[j];
			y[i*n+j] = c[i] + d[j];
		}
	sort(x,x+n*n);
	sort(y,y+n*n);
	
	int ans = 0;
	fr(i, n*n) {
		auto it = equal_range(x, x+n*n, -y[i]);
		if (it.first != it.second) ans += it.second - it.first;
	}
	cout << ans << endl;
}
