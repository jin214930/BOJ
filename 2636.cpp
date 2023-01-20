#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], visited[100][100], cnt1, cnt2;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (a[y][x] == 1) {
		v.push_back({ y, x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
			continue;
		if (!visited[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	while (true) {
		dfs(0, 0);
		for (auto i : v) {
			cnt2++;
			a[i.first][i.second] = 0;
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0)
					flag = false;
			}
		}
		cnt1++;
		if (flag)
			break;
		memset(visited, 0, sizeof(visited));
		cnt2 = 0;
		v.clear();
	}

	cout << cnt1 << '\n' << cnt2;

	return 0;
}