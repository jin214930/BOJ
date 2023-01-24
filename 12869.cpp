#include <bits/stdc++.h> 
using namespace std;

int n, a[3], visited[64][64][64];
int d[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	queue<tuple<int, int, int>> q;
	visited[a[0]][a[1]][a[2]] = 1;
	q.push({ a[0], a[1], a[2] });

	while (q.size()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		if (visited[0][0][0])
			break;
		for (int i = 0; i < 6; i++) {
			int na = max(0, a - d[i][0]);
			int nb = max(0, b - d[i][1]);
			int nc = max(0, c - d[i][2]);
			if (visited[na][nb][nc])
				continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	}

	cout << visited[0][0][0] - 1;

	return 0;
}