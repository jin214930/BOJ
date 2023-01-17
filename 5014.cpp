#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d, visited[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> f >> s >> g >> u >> d;

	memset(visited, -1, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = 0;

	while (q.size()) {
		int v = q.front();
		q.pop();
		int a1 = v + u;
		int a2 = v - d;
		if (a1 >= 1 && a1 <= f && visited[a1] == -1) {
			q.push(a1);
			visited[a1] = visited[v] + 1;
		}
		if (a2 >= 1 && a2 <= f && visited[a2] == -1) {
			q.push(a2);
			visited[a2] = visited[v] + 1;
		}
	}

	if (visited[g] == -1)
		cout << "use the stairs";
	else
		cout << visited[g];

	return 0;
}