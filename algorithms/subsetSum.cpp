// Returns true if there exists a subset 
// with given sum in arr[] 
// knapsack like

#include <iostream>
#include <stdbool.h> 

using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)

bool isSubsetSum(int arr[], int n, int sum) 
{ 
	// The value of subset[i%2][j] will be true 
	// if there exists a subset of sum j in 
	// arr[0, 1, ...., i-1] 
	bool subset[2][sum + 1]; 

	for (int i = 0; i <= n; i++) { 
		for (int j = 0; j <= sum; j++) { 

			// A subset with sum 0 is always possible 
			if (j == 0) 
				subset[i % 2][j] = true;
			// If there exists no element no sum is possible 
			else if (i == 0)
				subset[i % 2][j] = false; 
			else if (arr[i - 1] <= j) 
                // checking possible sum (other - arr value) OR copying 
				subset[i % 2][j] = subset[(i + 1) % 2][j - arr[i - 1]] 
                                || subset[(i + 1) % 2][j]; 
			else //just copying
				subset[i % 2][j] = subset[(i + 1) % 2][j];
		} 
	} 

	return subset[n % 2][sum]; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 6, 2, 5 }; 
	int sum = 7; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (isSubsetSum(arr, n, sum) == true) 
		printf("There exists a subset with given sum"); 
	else
		printf("No subset exists with given sum"); 
	return 0; 
} 
