#include <bits/stdc++.h> 
using namespace std;

int n, sy, sx, x, y, s = 2, cnt, ans, a[20][20], visited[20][20];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0 , -1, 0, 1 };

bool bfs(int y, int x) {
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	q.push({ y, x });
	visited[y][x] = 1;

	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= n || nx < 0)
				continue;
			if (!visited[ny][nx] && a[ny][nx] <= s) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}
	
	int m_t = 999999999;
	for (int i = n -1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] > 0 && a[i][j] < 9 && a[i][j] < s && visited[i][j] && visited[i][j] <= m_t) {
				m_t = visited[i][j];
				sy = i;
				sx = j;
			}
		}
	}

	if (m_t == 999999999)
		return false;

	a[sy][sx] = 0;
	cnt++;
	if (cnt == s) {
		cnt = 0;
		s++;
	}
	ans += visited[sy][sx] - 1;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				a[i][j] = 0;
				sy = i;
				sx = j;
			}
		}
	}

	while (true) {
		if (bfs(sy, sx))
			continue;
		else
			break;
	}

	cout << ans;

	return 0;
}