#include <bits/stdc++.h>
using namespace std;

int n, g[10][10], ans = 999999999, visited[10][10], cnt;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
vector<int> tmp;

bool check() {
	for (int i = 0; i < 3; i++) {
		int y = v[tmp[i]].first;
		int x = v[tmp[i]].second;
		cnt += g[y][x];
		visited[y][x] = 1;
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny >= n || ny < 0 || nx >= n || nx < 0)
				return false;
			if (visited[ny][nx])
				return false;
			cnt += g[ny][nx];
			visited[ny][nx] = 1;
		}
	}

	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			v.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size() - 2; i++) {
		tmp.push_back(i);
		for (int j = i + 1; j < v.size() - 1; j++) {
			tmp.push_back(j);
			for (int k = j + 1; k < v.size(); k++) {
				tmp.push_back(k);
				memset(visited, 0, sizeof(visited));
				cnt = 0;
				if (check()) 
					ans = min(ans, cnt);
				tmp.pop_back();
			}
			tmp.pop_back();
		}
		tmp.pop_back();
	}

	cout << ans;

	return 0;
}
