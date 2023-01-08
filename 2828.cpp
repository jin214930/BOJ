#include <bits/stdc++.h>
using namespace std;

int n, m, j, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> j;
	int start = 1, end = m;

	while (j--) {
		int tmp;
		cin >> tmp;
		if (tmp < start) {
			ans += start - tmp;
			start = tmp;
			end = tmp + m - 1;
		}
		else if (tmp > end) {
			ans += tmp - end;
			end = tmp;
			start = tmp - m + 1;
		}
	}

	cout << ans;

	return 0;
}