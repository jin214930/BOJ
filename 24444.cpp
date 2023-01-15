#include <bits/stdc++.h>
using namespace std;

int n, m, r, visited[100001], cnt = 1;
vector<int> v[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	queue<int> q;
	q.push(r);
	visited[r] = cnt;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto i : v[u]) {
			if (!visited[i]) {
				cnt++;
				visited[i] = cnt;
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << visited[i] << '\n';

	return 0;
}