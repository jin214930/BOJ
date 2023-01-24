#include <bits/stdc++.h> 
using namespace std;

int r, c, ans, visited[26];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char a[20][20];

void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0)
			continue;
		if (!visited[a[ny][nx] - 'A']) {
			visited[a[ny][nx] - 'A'] = 1;
			dfs(ny, nx, cnt + 1);
			visited[a[ny][nx] - 'A'] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	}

	visited[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ans;

	return 0;
}