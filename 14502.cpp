#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10], visited[10][10], ans, cnt;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
			continue;
		if (!visited[ny][nx] && a[ny][nx] == 0)
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)
				v.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size() - 2; i++) {
		for (int j = i + 1; j < v.size() - 1; j++) {
			for (int k = j + 1; k < v.size(); k++) {
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				
				for (int p = 0; p < n; p++) {
					for (int q = 0; q < m; q++) {
						if (a[p][q] == 2)
							dfs(p, q);
					}
				}

				cnt = 0;
				for (int p = 0; p < n; p++) {
					for (int q = 0; q < m; q++) {
						if (!visited[p][q] && a[p][q] == 0)
							cnt++;
					}
				}

				if (ans < cnt)
					ans = cnt;
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << ans;

	return 0;
}