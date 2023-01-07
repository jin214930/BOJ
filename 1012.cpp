#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, a[50][50], visited[50][50];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny, nx;
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		if (a[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		int ans = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && !visited[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << '\n';
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}