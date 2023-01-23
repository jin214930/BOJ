#include <bits/stdc++.h> 
using namespace std;

char a[1000][1000];
int r, c, y, x, ans, fire[1000][1000], visited[1000][1000];
int dy[] = { -1,0,1,0 }; 
int dx[] = { 0,-1,0,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> r >> c;
	fill(&fire[0][0], & fire[0][0] + 1000 * 1000, 999999999);
	queue<pair<int, int>> q1, q2;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'F') {
				fire[i][j] = 1;
				q1.push({ i, j });
			}
			if (a[i][j] == 'J') {
				visited[i][j] = 1;
				q2.push({ i , j });
			}
		}
	}

	while (q1.size()) {
		tie(y, x) = q1.front();
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
				continue;
			if (fire[ny][nx] == 999999999 && a[ny][nx] != '#') {
				fire[ny][nx] = fire[y][x] + 1;
				q1.push({ ny, nx });
			}
		}
	}

	while (q2.size()) {
		y = q2.front().first;
		x = q2.front().second;
		q2.pop();
		if (y == r - 1 || y == 0 || x == c - 1 || x == 0) {
			ans = visited[y][x];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
				continue;
			if (!visited[ny][nx] && a[ny][nx] != '#' && fire[ny][nx] > visited[y][x] + 1) {
				visited[ny][nx] = visited[y][x] + 1;
				q2.push({ ny, nx });
			}
		}
	}

	if (ans == 0)
		cout << "IMPOSSIBLE";
	else
		cout << ans;
	
	return 0;
}