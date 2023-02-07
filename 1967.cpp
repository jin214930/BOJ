#include <bits/stdc++.h> 
using namespace std;

int n, a, b, w, ans, visited[10001];
vector<pair<int, int>> adj[10001];

void dfs(int x, int cnt) {
	ans = max(ans, cnt);
	for (auto i : adj[x]) {
		if (!visited[i.first]) {
			visited[i.first] = 1;
			dfs(i.first, cnt + i.second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i, 0);
	}

	cout << ans;

	return 0;
}