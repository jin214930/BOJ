#include <bits/stdc++.h>
using namespace std;

int m, n, a[1003][1003], visited[1003][1003], ans;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				q.push({ i, j });
				visited[i][j] = 0;
			}
			else if (a[i][j] == -1)
				visited[i][j] = 0;
		}
	}

	while (q.size()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
				continue;
			if (a[ny][nx] == 0 && visited[ny][nx] == -1) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == -1) {
				cout << -1;
				return 0;
			}
			if (visited[i][j] > ans)
				ans = visited[i][j];
		}
	}

	cout << ans;

	return 0;
}