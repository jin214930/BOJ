#include <bits/stdc++.h> 
using namespace std;

int k, v, e, a, b, x, check[20001];
vector<int> adj[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> k;
	while (k--) {
		cin >> v >> e;
		for (int i = 1; i <= v; i++) 
			adj[i].clear();		
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		memset(check, 0, sizeof(check));
		queue<int> q;
		for (int i = 1; i <= v; i++) {
			if (!check[i]) {
				check[i] = 1;
				q.push(i);
			}
			while (q.size()) {
				int x = q.front();
				q.pop();
				for (int i : adj[x]) {
					if (!check[i]) {
						if (check[x] == 1)
							check[i] = 2;
						else
							check[i] = 1;
						q.push(i);
					}
				}
			}
		}

		bool flag = true;
		for (int i = 1; i <= v; i++) {
			for (int j : adj[i]) {
				if (check[i] == check[j]) {
					flag = false;
				}
			}
		}

		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}