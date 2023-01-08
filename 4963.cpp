#include <bits/stdc++.h>
using namespace std;

int w, h, a[55][55], visited[55][55];
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, 1, -1, 1, -1};

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny > h || nx < 0 || nx > w)
			continue;
		if (a[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int ans = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				cin >> a[i][j];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && !visited[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << '\n';
		memset(visited, 0, sizeof(visited));
		memset(a, 0, sizeof(a));
	}

	return 0;
}