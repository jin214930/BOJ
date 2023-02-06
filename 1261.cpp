#include <bits/stdc++.h> 
using namespace std;

int n, m, x, y, cnt, visited[100][100];
char a[100][100];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			visited[i][j] = 999999999;
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	visited[0][0] = 0;
	while (q.size()) {
		tie(y, x, cnt) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
				continue;
			if (a[ny][nx] == '0') {
				if (visited[ny][nx] > cnt) {
					visited[ny][nx] = cnt;
					q.push({ ny, nx, cnt });
				}
			}
			else {
				if (visited[ny][nx] > cnt + 1) {
					visited[ny][nx] = min(visited[ny][nx], cnt + 1);
					q.push({ ny, nx, cnt + 1 });
				}
			}
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
}