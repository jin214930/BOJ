#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt, a[105][105], visited[105][105];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<int> ans;

void dfs(int y, int x) {
	visited[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ny, nx;
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
			continue;
		if (a[ny][nx] == 0 && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	while (k--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++)
				a[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				dfs(i, j);
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';

	return 0;
}