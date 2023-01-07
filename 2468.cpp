#include <bits/stdc++.h>
using namespace std;

int n, ans = 1, a[105][105], visited[105][105];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int h) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny, nx;
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;
		if (a[ny][nx] > h && !visited[ny][nx])
			dfs(ny, nx, h);
	}
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

	for (int i = 1; i <= 100; i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j][k] > i && !visited[j][k]) {
					dfs(j, k, i);
					cnt++;
				}
			}
		}

		if (cnt > ans)
			ans = cnt;

		memset(visited, 0, sizeof(visited));
	}

	cout << ans;

	return 0;
}