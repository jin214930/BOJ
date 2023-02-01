#include <bits/stdc++.h> 
using namespace std;

int n, k, x, visited[2][500001], t = 1;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}
	
	queue<int> q;
	q.push(n);
	visited[0][n] = 1;

	while (q.size()) {
		k += t;
		if (k > 500000)
			break;
		if (visited[t % 2][k]) {
			flag = true;
			break;
		}
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			x = q.front();
			q.pop();
			for (int nx : {x - 1, x + 1, 2 * x}) {
				if (nx >= 0 && nx <= 500000 && !visited[t % 2][nx]) {
					visited[t % 2][nx] = visited[(t - 1) % 2][x] + 1;
					if (nx == k) {
						flag = true;
						break;
					}
					q.push(nx);
				}
			}
			if (flag)
				break;
		}
		if (flag)
			break;
		t++;
	}

	if (flag)
		cout << t;
	else
		cout << -1;

	return 0;
}