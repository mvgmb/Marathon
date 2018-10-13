#include <bits/stdc++.h>

using namespace std;

int parent[200005];
int size[200005];
vector<tuple<int,int,int> > lis;

int find(int x) {
	if(x != parent[x]) parent[x] = find(parent[x]);
	return parent[x];
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a,int b) {
	a = find(a);
	b = find(b);
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	parent[b] = a;
}

int main() {
	int m, n, u, v, w, i, c, tot;
	while(cin >> m >> n && m != 0 && n != 0) {
		for(i=0;i<m;i++) {
			parent[i] = i;
			size[i] = 1;
		}
		lis.clear();
		tot = 0;
		while(n--) {
			cin >> u >> v >> w;
			tot += w;
			lis.push_back(make_tuple(w,u,v));
		}
		sort(lis.begin(),lis.end());
		c = 0;
		for(i=0;i<lis.size();i++) {
			tie(w,u,v) = lis[i];
			if(!same(u,v)) {
				c += w;
				unite(u,v);
			}
		}
		cout << (tot- c) << endl;
	}
	return 0;
}