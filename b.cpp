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

long long f(long long x) {
	long long sum = 0;
	for (long long k = 2; k * k * k <= x; k++) {
		sum += x / (k * k * k);
	}
	return sum;
}

int main() {
    long long m;
	cin >> m;

	long long r = 1e15;
	long long l = -1;

	while (r - l > 1) {
		long long mid = (r + l) / 2;

		if (f(mid) >= m) {
			r = mid;
		} else {
			l = mid;
		}
	}

	if (f(r) != m) r = -1;
	cout << r << endl;

}
