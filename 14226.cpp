#include <bits/stdc++.h> 
using namespace std;

int s, x, y, t, visited[1001][1001], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> s;

	queue<tuple<int, int, int>> q;
	visited[1][0] = 1;
	q.push({1, 0, 0});

	while (q.size()) {
		tie(x, y, t) = q.front();
		q.pop();

		if (x == s) {
			ans = t;
			break;
		}
		
		if (x > 0 && x < 1001) {
			if (!visited[x][x]) {
				visited[x][x] = 1;
				q.push({ x, x, t + 1 });
			}
			if (!visited[x - 1][y]) {
				visited[x - 1][y] = 1;
				q.push({ x - 1, y, t + 1 });
			}
			if (y > 0 && x + y < 1001 && !visited[x + y][y]) {
				visited[x + y][y] = 1;
				q.push({ x + y, y, t + 1 });
			}
		}
	}

	cout << ans;

	return 0;
}