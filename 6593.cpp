#include <bits/stdc++.h> 
using namespace std;

int l, r, c, x, y, z, d, e, f, visited[30][30][30];
char a[30][30][30];
int dz[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { -1, 0, 1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	while (true) {
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0)
			break;

		queue<tuple<int, int, int>> q;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> a[i][j][k];
					if (a[i][j][k] == 'S') {
						q.push({ i, j, k });
						visited[i][j][k] = 1;
					}
					else if (a[i][j][k] == 'E') {
						d = i;
						e = j;
						f = k;
					}
				}
			}
		}

		while (q.size()) {
			tie(z, y, x) = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nz >= l || nz < 0 || ny >= r || nz < 0 || nx >= c || nx < 0)
					continue;
				if ((a[nz][ny][nx] == '.' || a[nz][ny][nx] == 'E') && !visited[nz][ny][nx]) {
					q.push({ nz, ny, nx });
					visited[nz][ny][nx] = visited[z][y][x] + 1;
				}
			}
		}

		if (visited[d][e][f])
			cout << "Escaped in " << visited[d][e][f] - 1 << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
	
	return 0;
}