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

bool f(vi i, vi j){
	if (i.size() != j.size()) return i.size() < j.size();
	else return i < j;
}

int main() {
    int n;
	cin >> n;
	vector< vi > sub;
	for(int i = 0; i< (1<<n); i++){
		vi tmp;
		fr(j,n) {
			if (i & (1 << j)) {
				tmp.pb(j);
			}
		}
		sub.pb(tmp);
	}
	sort(all(sub), f);
	tr(sub, it) {
		fr(i, (*it).size()){
			cout << (*it)[i]+1 << " ";
		}
		cout << endl;
	}


}
