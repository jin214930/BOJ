#include <bits/stdc++.h> 
using namespace std;

int n, x, ans, cnt[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	cin >> x;

	for (int i = 1; i <= x / 2; i++) {
		if (2 * i == x)
			continue;
		if (x - i > 1000000)
			continue;
		if (cnt[i] && cnt[x - i])
			ans++;
	}

	cout << ans;

	return 0;
}