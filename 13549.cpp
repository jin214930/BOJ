#include <bits/stdc++.h> 
using namespace std;

int n, k, visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(visited, visited + 100001, 999999999);
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (x == k)
			break;
		if (x * 2 <= 100000 && visited[x * 2] > visited[x]) {
			visited[x * 2] = visited[x];
			q.push(x * 2);
		}

		for (int i : { x - 1, x + 1}) {
			if (i <= 100000 && i >= 0 && visited[i] > visited[x]) {
				visited[i] = visited[x] + 1;
				q.push(i);
			}
		}
	}

	cout << visited[k] - 1;

	return 0;
}