#include <bits/stdc++.h>
using namespace std;

int n, m, visited[51][51], ans;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char a[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				queue<pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = 1;
				while (q.size()) {
					int y, x;
					tie(y, x) = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny >= n || ny < 0 || nx >= m || nx < 0)
							continue;
						if (a[ny][nx] == 'L' && !visited[ny][nx]) {
							visited[ny][nx] = visited[y][x] + 1;
							q.push({ ny, nx });
							ans = max(ans, visited[ny][nx]);
						}
					}
				}
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << ans - 1;

	return 0;
}
