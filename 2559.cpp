#include <bits/stdc++.h>
using namespace std;

int n, k, psum[100005], ans = INT_MIN;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		psum[i] = psum[i - 1] + tmp;
	}

	for (int i = 0; i <= n - k; i++) {
		if (ans < psum[i + k] - psum[i])
			ans = psum[i + k] - psum[i];
	}

	cout << ans;

	return 0;
}