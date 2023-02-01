#include <bits/stdc++.h> 
using namespace std;

int n, m, x, y, connet[101], visited[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		connet[x] = y;
	}
	
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (q.size()) {
		x = q.front();
		q.pop();
		if (x == 100)
			break;
		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx > 100 || visited[nx])
				continue;
			if (!connet[nx]) {
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
			else {
				if (!visited[connet[nx]]) {
					visited[connet[nx]] = visited[x] + 1;
					q.push(connet[nx]);
				}
			}
		}
	}
	
	cout << visited[100] - 1;

	return 0;
}