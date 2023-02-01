#include <bits/stdc++.h> 
using namespace std;

int n, m, h, a, b, ans = 999999999, visited[35][13];

bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start])
				start++;
			else if (visited[j][start - 1])
				start--;
		}
		if (start != i)
			return false;
	}
	return true;
}

void go(int start, int cnt) {
	if (cnt > 3 || cnt >= ans)
		return;
	if (check()) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = start; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
				continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visited[a][b] = 1;
	}

	go(1, 0);

	if (ans == 999999999)
		cout << -1;
	else
		cout << ans;

	return 0;
}