#include <bits/stdc++.h> 
using namespace std;

int n, dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;

	dp[2] = 1;
	for (int i = 5; i <= n; i++) {
		if (dp[i - 1] != 1 && dp[i - 3] != 1 && dp[i - 4] != 1)
			dp[i] = 1;
	}

	cout << (dp[n] ? "CY" : "SK");


	return 0;
}