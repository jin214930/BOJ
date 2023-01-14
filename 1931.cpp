#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int te, ts;
		cin >> ts >> te;
		v.push_back({ te, ts });
	}
	
	sort(v.begin(), v.end());
	
	t = v[0].first;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= t) {
			ans++;
			t = v[i].first;
		}
	}

	cout << ans;

	return 0;
}