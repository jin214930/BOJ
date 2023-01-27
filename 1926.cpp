#include <bits/stdc++.h> 
using namespace std;

int n, m, a[500][500], visited[500][500], cnt, s, max_s;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
			continue;
		if (a[ny][nx] == 1 && !visited[ny][nx]) {
			s++;
			dfs(ny, nx);
		}
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				s = 1;
				dfs(i, j);
				cnt++;
				max_s = max(s, max_s);
			}
		}
	}

	cout << cnt << '\n' << max_s;
	
	
	return 0;
}