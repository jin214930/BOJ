#include <bits/stdc++.h> 
using namespace std;

int n, k, x, visited[100001], pre[100001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> k;
	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (q.size()) {
		x = q.front();
		q.pop();

		if (x == k) 
			break;

		for (int i : {x - 1, x + 1, 2 * x}) {
			if (i >= 0 && i <= 100000 && !visited[i]) {
				q.push(i);
				visited[i] = visited[x] + 1;
				pre[i] = x;
			}
			
		}
	}

	cout << visited[k] - 1 << '\n';
	for (int i = k; i != n; i = pre[i])
		v.push_back(i);
	v.push_back(n);
	reverse(v.begin(), v.end());
	for (int i : v)
		cout << i << ' ';

	return 0;
}