// C++ program to find the number
// of subsequences with gcd 1
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// Recursive function to calculate the number
// of subsequences with gcd 1 starting with
// particular index
int func(int ind, int g, int dp[][MAX], int n, int a[])
{

	// Base case
	if (ind == n) {
		if (g == 1)
			return 1;
		else
			return 0;
	}

	// If already visited
	if (dp[ind][g] != -1)
		return dp[ind][g];

	// Either we take or we do not
	int ans = max(func(ind + 1, g, dp, n, a)+1
			,func(ind + 1, gcd(a[ind], g), dp, n, a));

	// Return the answer
	return dp[ind][g] = ans;
}

// Function to return the number of subsequences
int countSubsequences(int a[], int n)
{

	// Hash table to memoize
	int dp[n][MAX];
	memset(dp, -1, sizeof dp);

	// Count the number of subsequences
	int count = 0;

	// Count for every subsequence
	for (int i = 0; i < n; i++)
		count += func(i + 1, a[i], dp, n, a);

	return count;
}

// Driver Code
int main()
{
	int a[] = { 3, 4, 8, 16 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << countSubsequences(a, n);
	return 0;
}
