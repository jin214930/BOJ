#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10001], cnt[10001], idx;
vector<int> a[10001];

void dfs(int n) {
	visited[n] = 1;
	for (int i : a[n]) {
		if (!visited[i]) 
			dfs(i);
	}
	cnt[idx]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		a[q].push_back(p);
	}
	
	for (int i = 1; i <= n; i++) {
		idx = i;
		dfs(i);
		memset(visited, 0, sizeof(visited));
	}

	int target = *max_element(cnt + 1, cnt + n + 1);
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == target)
			cout << i << ' ';
	}

	return 0;
}