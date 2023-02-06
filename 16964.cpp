#include <bits/stdc++.h> 
using namespace std;

int n, a, b, visited[100001];
vector<int> adj[100001], v;

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
		v.push_back(a);
	}

	if (v[0] != 1) {
		cout << 0;
		return 0;
	}

	visited[1] = 1;
	for (int i = 1; i < v.size(); i++) {
		if (visited[v[i]]) {
			cout << 0;
			return 0;
		}
		bool flag = false;
		int cnt = 0;
		for (int j : adj[v[i - 1]]) {
			if (visited[j])
				cnt++;
			else if (j == v[i])
				flag = true;
		}
		if (cnt == adj[v[i - 1]].size())
			flag = true;
		if (flag) {
			visited[v[i]] = 1;
			continue;
		}
		else {
			cout << 0;
			return 0;
		}
	}

	cout << 1;	

	return 0;
}