#include <bits/stdc++.h> 
using namespace std;

int n, m, k, x, y, ans = -999999999, a[10][10], visited[10][10];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void go(int cnt, int sum) {
	if (cnt == k) {
		ans = max(ans, sum);
		return;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				bool flag = false;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= n || ny < 0 || nx >= m || nx < 0)
						continue;
					if (visited[ny][nx])
						flag = true;
				}
				if (flag)
					continue;
				visited[i][j] = 1;
				go(cnt + 1, sum + a[i][j]);
				visited[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			cin >> a[i][j];
	}

	go(0, 0);

	cout << ans;

	return 0;
}