#include <bits/stdc++.h>
using namespace std;

int n, visited[100][100], ans1, ans2;
string s;
char a[100][100];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= n || nx < 0)
			continue;
		if (!visited[ny][nx] && a[ny][nx] == a[y][x])
			dfs(ny, nx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			a[i][j] = s[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'R')
				a[i][j] = 'G';
		}
	}
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans2++;
			}
		}
	}

	cout << ans1 << ' ' << ans2;

	return 0;
}