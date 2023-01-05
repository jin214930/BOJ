#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n) {
		int ans = 0;
		int ones = 1;

		while (true) {
			ans++;
			if (ones % n == 0)
				break;
			ones = (ones * 10 + 1) % n;
		}

		cout << ans << '\n';
	}

	return 0;
}