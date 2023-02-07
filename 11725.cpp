#include <bits/stdc++.h> 
using namespace std;

int n, a, b, p[100001];
vector<int> adj[100001];

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

	queue<int> q;
	q.push(1);
	p[1] = 999999999;
	while (q.size()) {
		a = q.front();
		q.pop();
		for (int i : adj[a]) {
			if (!p[i]) {
				p[i] = a;
				q.push(i);
			}

		}
	}

	for (int i = 2; i <= n; i++)
		cout << p[i] << '\n';

	return 0;
}