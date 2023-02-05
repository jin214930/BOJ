#include <bits/stdc++.h> 
using namespace std;

int n, m, sx, sy, cnt, visited[50][50];
char a[50][50];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
			continue;
		if (!visited[ny][nx] && a[ny][nx] == a[y][x]) {
			visited[ny][nx] = 1;
			cnt++;
			dfs(ny, nx);
		}
		if (visited[ny][nx] && cnt >= 4 && ny == sy && nx == sx && a[ny][nx] == a[sy][sx]) {
			cout << "Yes";
			exit(0);
		}
	}
	cnt--;
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			sy = i;
			sx = j;
			cnt = 1;
			visited[i][j] = 1;
			dfs(i, j);
		}
	}

	cout << "No";

	return 0;
}