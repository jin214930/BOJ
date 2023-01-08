#include <bits/stdc++.h>
using namespace std;

int t, l, visited[301][301];
int dx[] = { 2, 1, 2, 1, -1, -2, -1, -2 };
int dy[] = { 1, 2, -1, -2, 2, 1, -2, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> l;
		int x, y;
		cin >> x >> y;
		queue<pair<int, int>> q;
		visited[y][x] = 1;
		q.push({ y, x });
		while (q.size()) {
			tie(y, x) = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= l || nx < 0 || nx >= l)
					continue;
				if (visited[ny][nx])
					continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}

		cin >> x >> y;
		cout << visited[y][x] - 1 << '\n';
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}