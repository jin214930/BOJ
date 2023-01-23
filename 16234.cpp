#include <bits/stdc++.h>
using namespace std;

int n, l, r, a[51][51], visited[51][51], sum, cnt;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= n || nx < 0)
			continue;
		if (!visited[ny][nx] && abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
			visited[ny][nx] = 1;
			v.push_back({ ny, nx });
			sum += a[ny][nx];
			dfs(ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	while (true) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i, j });
					sum = a[i][j];
					dfs(i, j);
					if (v.size() == 1)
						continue;
					for (auto k : v) {
						a[k.first][k.second] = sum / v.size();
						flag = true;
					}
				}
			}
		}

		if (!flag)
			break;
		cnt++;
		memset(visited, 0, sizeof(visited));
	}

	cout << cnt;

	return 0;
}
