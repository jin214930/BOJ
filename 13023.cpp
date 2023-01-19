#include <bits/stdc++.h>
using namespace std;

int n, m, ans, visited[2000];
vector<int> adj[2000];

void dfs(int k, int depth) {
	visited[k] = 1;
	if (depth == 4) {
		ans = 1;
		return;
	}
	for (auto i : adj[k]) {
		if (!visited[i] && ans != 1) 
			dfs(i, depth + 1);
	}
	visited[k] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 0);
		if (ans)
			break;
	}
	
	cout << ans;

	return 0;
}