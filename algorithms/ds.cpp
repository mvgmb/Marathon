#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <set>
#include <map>

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

const int maxN = 200005;
int parent[maxN], size[maxN];

void init(int n) {
	fr(i, n) {
		parent[i] = i;
	 	size[i] = 1;
	}
}

int findSet(int x) {
	if (x != parent[x]) parent[x] = findSet(parent[x]);
	return parent[x];
}
 
bool isSameSet(int a, int b) {
	return findSet(a) == findSet(b);
}
 
void uniteSet(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	parent[b] = a;
}

int main() {
    int t, n, z, x, y;
	cin >> t;
	map<string, int> m;
	string a, b;
	while(t--) { // t - test cases
		m.clear();
		z = 0;
		cin >> n;
		init(2*n);
		while(n--) { // n - N
			cin >> a >> b;
			if(!m.count(a)) m.insert({a,z++});
			if(!m.count(b)) m.insert({b,z++});
			x = m[a];
			y = m[b];
			if(!isSameSet(x,y)) uniteSet(x,y);
			cout << size[findSet(y)] << "\n";
		}
	}
}