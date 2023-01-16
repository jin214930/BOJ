#include <bits/stdc++.h>
using namespace std;

int n, a[2300][2300], ans[3];

void go(int y, int x, int size) {
	if (size == 1) {
		ans[a[y][x] + 1]++;
		return;
	}

	int tmp = a[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tmp != a[i][j]) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						go(y + size / 3 * k, x + size / 3 * l, size / 3);
					}
				}
				return;
			}
		}
	}
	ans[tmp + 1]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, n);

	for (int i : ans)
		cout << i << '\n';

	return 0;
}