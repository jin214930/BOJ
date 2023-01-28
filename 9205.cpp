#include <bits/stdc++.h> 
using namespace std;

int t, n, x, y, sx, sy, ex, ey, visited[100];
vector <pair<int, int>> v;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	while (q.size()) {
		tie(x, y) = q.front();
		q.pop();
		if (abs(x - ex) + abs(y - ey) <= 1000) {
			cout << "happy\n";
			return;
		}
		for (int i = 0; i < v.size(); i++) {
			if (abs(x - v[i].first) + abs(y - v[i].second) <= 1000) {
				if (!visited[i]) {
					visited[i] = 1;
					q.push({ v[i].first, v[i].second });
				}
			}
		}
	}
	cout << "sad\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;
		cin >> sx >> sy;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x, y });
		}
		cin >> ex >> ey;

		bfs();

		memset(visited, 0, sizeof(visited));
		v.clear();
	}

	return 0;
}