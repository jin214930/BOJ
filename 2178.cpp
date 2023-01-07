#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][105], visited[105][105];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = s[j] - '0';
	}

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0, 0 });

	while (q.size()) {
		int x, y;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] == 0)
				continue;
			if (visited[ny][nx])
				continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	cout << visited[n - 1][m - 1];


	return 0;
}