#include <bits/stdc++.h> 
using namespace std;

int r, c, k, cnt, visited[5][5];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char a[5][5];

void dfs(int y, int x, int depth) {
	if (depth == k && y == 0 && x == c - 1) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0)
			continue;
		if (!visited[ny][nx] && a[ny][nx] != 'T') {
			visited[ny][nx] = 1;
			dfs(ny, nx, depth + 1);
			visited[ny][nx] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	}

	visited[r - 1][0] = 1;
	dfs(r - 1, 0, 1);

	cout << cnt;

	return 0;
}