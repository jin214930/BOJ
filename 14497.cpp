#include <bits/stdc++.h> 
using namespace std;

int n, m, x1, b, x2, y2, x, y, cnt, visited[300][300];
char a[300][300];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m;
	cin >> b >> x1 >> y2 >> x2;
	x1--;
	b--;
	x2--;
	y2--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push({ b, x1 });
	visited[b][x1] = 1;
	
	while (a[y2][x2] != '0') {
		cnt++;
		queue<pair<int, int>> tmp;
		while (q.size()) {
			tie(y, x) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx])
					continue;
				visited[ny][nx] = cnt;
				if (a[ny][nx] != '0') {
					a[ny][nx] = '0';
					tmp.push({ ny, nx });
				}
				else
					q.push({ ny, nx });
			}
		}
		q = tmp;		
	}

	cout << visited[y2][x2];

	return 0;
}