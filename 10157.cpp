#include <bits/stdc++.h>
using namespace std;

int c, r, k, arr[1001][1001];
int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> r >> k;

	if (c * r < k) {
		cout << 0;
		return 0;
	}

	int x = 1, y = 1, cnt = 1;
	int dx = direction[0][0], dy = direction[0][1], d = 0;

	while (true) {
		arr[x][y] = cnt;
		if (k == cnt) {
			cout << x << ' ' << y;
			break;
		}
		cnt++;
		if ((x + dx == c + 1 || x + dx == 0) || (y + dy == r + 1 || y + dy == 0) || arr[x + dx][y + dy] != 0) {
			d = (d + 1) % 4;
			dx = direction[d][0];
			dy = direction[d][1];
		}
		x += dx;
		y += dy;
	}	

	return 0;
}