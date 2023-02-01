#include <bits/stdc++.h> 
using namespace std;

int r, c, sx, sy, x, y, ans, visited[1500][1500], visited_s[1500][1500];
char a[1500][1500];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> sq, wq, sq_tmp, wq_tmp;

bool swan() {
	while (sq.size()) {
		tie(y, x) = sq.front();
		sq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0 || visited_s[ny][nx])
				continue;
			visited_s[ny][nx] = 1;
			if (a[ny][nx] == '.')
				sq.push({ ny, nx });
			else if (a[ny][nx] == 'X')
				sq_tmp.push({ ny, nx });
			else
				return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L' || a[i][j] == '.') {
				visited[i][j] = 1;
				wq.push({ i, j });
			}
			if (a[i][j] == 'L') {
				sy = i;
				sx = j;
			}
		}
	}
	visited_s[sy][sx] = 1;
	sq.push({ sy, sx });

	while (true) {
		if (swan())
			break;
		while (wq.size()) {
			tie(y, x) = wq.front();
			wq.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= r || ny < 0 || nx >= c || nx < 0 || visited[ny][nx])
					continue;
				if (a[ny][nx] == 'X') {
					visited[ny][nx] = 1;
					a[ny][nx] = '.';
					wq_tmp.push({ ny, nx });
				}
			}
		}
		wq = wq_tmp;
		sq = sq_tmp;
		wq_tmp = queue<pair<int, int>>();
		sq_tmp = queue<pair<int, int>>();
		ans++;
	}

	cout << ans;

	return 0;
}