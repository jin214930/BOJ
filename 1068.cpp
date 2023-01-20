#include <bits/stdc++.h>
using namespace std;

int n, x, root;
vector<int> adj[51];

int dfs(int k) {
	int ans = 0, cnt = 0;
	for (int i : adj[k]) {
		if (i == x)
			continue;
		ans += dfs(i);
		cnt++;
	}
	if (cnt == 0)
		return 1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1)
			root = i;
		else adj[tmp].push_back(i);
	}

	cin >> x;
	if (x == root) {
		cout << 0;
		return 0;
	}

	cout << dfs(root);

	return 0;
}
