#include <bits/stdc++.h> 
using namespace std;

// 14503
int n, m, r, c, d, cnt, a[50][50], visited[50][50];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		d--;
		if (d < 0)
			d += 4;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
			continue;
		if (!visited[ny][nx] && !a[ny][nx]) {
			cnt++;
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}

	int bd = d > 1 ? d - 2 : d + 2;
	int by = y + dy[bd];
	int bx = x + dx[bd];
	if (by < n && by >= 0 && bx < m && by >= 0) {
		if (!a[by][bx])
			dfs(by, bx);
		else {
			cout << cnt;
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	visited[r][c] = 1;
	cnt = 1;
	dfs(r, c);

	cout << cnt;

	return 0;
}