#include <bits/stdc++.h> 
using namespace std;

int n, a, b, s, cnt, cycle[3001], visited[3001];
bool flag;
vector<int> adj[3001];

void dfs(int k) {
	for (int x : adj[k]) {
		if (!cycle[x]) {
			cycle[x] = 1;
			cnt++;
			dfs(x);
			if (flag)
				return;
			cnt--;
			cycle[x] = 0;
		}
		else {
			if (x == s && cnt >= 3) {
				flag = true;
				return;
			}
		}
	}
}

int bfs(int n) {
	queue<int> q;
	memset(visited, 0, sizeof(visited));
	q.push(n);
	visited[n] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int nx : adj[x]) {
			if (!visited[nx] && !cycle[nx]) {
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
			if (cycle[nx])
				return visited[x];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(cycle, 0, sizeof(cycle));
		s = i;
		cnt = 1;
		cycle[i] = 1;
		dfs(i);
		if (flag)
			break;
	}

	for (int i = 1; i <= n; i++) {
		if (cycle[i])
			cout << 0 << ' ';
		else {
			cout << bfs(i) << ' ';
		}
	}

	return 0;
}