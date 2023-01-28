#include <bits/stdc++.h> 
using namespace std;

int n, m, ans = 1, dp[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m;
	
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	int base = 0;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		ans *= dp[tmp - base - 1];
		base = tmp;
	}

	if (base != n) 
		ans *= dp[n - base];

	cout << ans;

	return 0;
}