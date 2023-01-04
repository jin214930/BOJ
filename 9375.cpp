#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		int ans = 1;
		map<string, int> mp;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			mp[s2]++;
		}

		for (auto i : mp) 
			ans *= i.second + 1;

		cout << ans - 1 << '\n';
	}

	return 0;
}