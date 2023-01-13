#include <bits/stdc++.h>
using namespace std;

int n, cnt, ans = 665;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (true) {
		ans++;
		string s = to_string(ans);
		if (s.find("666") != string::npos)
			cnt++;
		if (cnt == n)
			break;
	}

	cout << ans;

	return 0;
}