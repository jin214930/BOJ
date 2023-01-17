#include <bits/stdc++.h>
using namespace std;

int n, m, a[101][101], d[101][101], ans[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		a[p][q] = 1;
		a[q][p] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				d[i][j] = 0;
			else if (a[i][j])
				d[i][j] = a[i][j];
			else
				d[i][j] = 1000000000;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			ans[i] += d[i][j];
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == *min_element(ans + 1, ans + n + 1)) {
			cout << i;
			return 0;
		}
	}

	return 0;
}