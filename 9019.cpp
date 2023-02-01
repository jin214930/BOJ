#include <bits/stdc++.h> 
using namespace std;

int t, a, b, x, visited[10000];
string s;
string op[] = { "D", "S", "L", "R" };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> a >> b;

		queue<pair<int, string>> q;
		q.push({a, ""});
		visited[a] = 1;

		while (q.size()) {
			tie(x, s) = q.front();
			q.pop();
			if (x == b) {
				cout << s << '\n';
				break;
			}
			int nx[4];
			nx[0] = x * 2 % 10000;
			nx[1] = (x ? x - 1 : 9999);
			nx[2] = (x % 1000) * 10 + x / 1000;
			nx[3] = (x % 10) * 1000 + x / 10;
			for (int i = 0; i < 4; i++) {
				if (!visited[nx[i]]) {
					visited[nx[i]] = 1;
					q.push({ nx[i], s + op[i] });
				}
			}
		}

		memset(visited, 0, sizeof(visited));
	}

	return 0;
}