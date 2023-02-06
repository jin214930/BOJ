#include <bits/stdc++.h> 
using namespace std;

int n, a, b, visited[100001];
vector<int> adj[100001];
queue<int> tq;

bool bfs() {
	if (tq.front() != 1)
		return false;

	queue<int> q;
	q.push(1);
	visited[1] = 1;
	tq.pop();

	while (q.size()) {
		int x = q.front();
		q.pop();
		int cnt = adj[x].size();
		for (int nx : adj[x]) {
			if (visited[nx])
				cnt--;
		}

		while (cnt) {
			auto it = find(adj[x].begin(), adj[x].end(), tq.front());
			if (it != adj[x].end()) {
				q.push(*it);
				visited[*it] = 1;
				tq.pop();
				cnt--;
			}
			else
				return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> a;
		tq.push(a);
	}

	cout << bfs();
	
	return 0;
}