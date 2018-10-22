#include <iostream> 
#include <string.h>
#include <map>

using namespace std; 
const int maxN = 100000;
double bSum[maxN];

double binomialSum(int x, int n, int k) { 
	if(bSum[x] == 0){
		double sum = 0, term = 1; 
		for (int i = 1; i <= n && sum < k; ++i) {
			term *= x - i + 1;
			term /= i;
			sum += term;
		}
		bSum[x] = sum;
	}
	return bSum[x];
}
   
int minTrials(int n, int k) {
    int low = 1, high = k;
    while (low < high) {
		int mid = (low + high) / 2;
		if (binomialSum(mid, n, k) < k)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	memset(bSum, 0, maxN);
	
    int loop, k;
    cin >> loop;
    while(loop--){
		cin >> k;
		cout << minTrials(2, k) << endl;
    }
}
