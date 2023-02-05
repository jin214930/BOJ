#include <bits/stdc++.h> 
using namespace std;

int n, x, y, cnt = 1, ans = 999999999, a[100][100], visited[100][100], dist[100][100];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	for (int i = 0; i < n; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx] || !a[ny][nx])
			continue;
		visited[ny][nx] = cnt;
		dfs(ny, nx);
	}
}

void bfs(int d, int c) {
	queue<pair<int, int>> q;
	dist[d][c] = 1;
	q.push({ d, c });
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= n || nx < 0 || dist[ny][nx])
				continue;
			if (visited[ny][nx] && visited[d][c] != visited[ny][nx]) {
				ans = min(ans, dist[y][x]);
				return;
			}
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] && !visited[i][j]) {
				visited[i][j] = cnt;
				dfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				memset(dist, 0, sizeof(dist));
				bfs(i, j);
			}
		}
	}

	cout << ans - 1;

	return 0;
}