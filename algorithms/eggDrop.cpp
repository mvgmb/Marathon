// C++ program to find minimum 
// number of trials in worst case. 
#include <iostream> 

using namespace std; 

// Find sum of binomial coefficients xCi 
// (where i varies from 1 to n). If the sum 
// becomes more than K 
int binomialCoeff(int x, int n, int k) 
{ 
	int sum = 0, term = 1; 
	for (int i = 1; i <= n && sum < k; ++i) { 
		term *= x - i + 1; 
		term /= i; 
		sum += term; 
	} 
	return sum; 
} 
    
// Do binary search to find minimum 
// number of trials in worst case. 
int minTrials(int n, int k) 
{ 
	// Initialize low and high as 1st 
	// and last floors 
	int low = 1, high = k; 

	// Do binary search, for every mid, 
	// find sum of binomial coefficients and 
	// check if the sum is greater than k or not. 
	while (low < high) { 
		int mid = (low + high) / 2; 
		if (binomialCoeff(mid, n, k) < k) 
			low = mid + 1; 
		else
			high = mid;         
	} 
	return low; 
} 

/* Drier program to test above function*/
int main() 
{ 
    int eggs, no_floors; cin >> eggs >> no_floors;
	cout << minTrials(eggs, no_floors); // eggs and building size
	return 0; 
} 
