#include <bits/stdc++.h>
using namespace std;

int n, a[26][26], visited[26][26], cnt, ans;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<int> v;

void dfs(int y, int x) {
	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny > n || nx < 0 || nx > n)
			continue;
		if (a[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			a[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				v.push_back(cnt);
				ans++;
				cnt = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << ans << '\n';
	for (int i : v)
		cout << i << '\n';

	return 0;
}