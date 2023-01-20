#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001], visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	queue<int> q;
	q.push(n);

	while (q.size()) {
		int x = q.front();
		q.pop();
		if (x == k)
			break;
		int x1 = x - 1;
		int x2 = x + 1;
		int x3 = 2 * x;
		if (x1 >= 0 && x1 <= 100000 && !visited[x1]) {
			q.push(x1);
			visited[x1] = visited[x] + 1;
		}
		if (x2 >= 0 && x2 <= 100000 && !visited[x2]) {
			q.push(x2);
			visited[x2] = visited[x] + 1;
		}
		if (x3 >= 0 && x3 <= 100000 && !visited[x3]) {
			q.push(x3);
			visited[x3] = visited[x] + 1;
		}
	}

	cout << visited[k];

	return 0;
}