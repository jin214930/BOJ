#include <bits/stdc++.h> 
using namespace std;

int n, k, visited[100001], x, t, cnt, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> k;
	queue<pair<int, int>> q;
	q.push({ n, 0 });

	while (q.size()) {
		tie(x, t) = q.front();
		q.pop();
		visited[x] = 1;

		if (x == k) {
			if (cnt == 0) {
				ans = t;
				cnt++;
			}
			else if (ans == t)
				cnt++;
		}

		for (int i : {x - 1, x + 1, 2 * x}) {
			if (i >= 0 && i <= 100000 && !visited[i]) 
				q.push({ i, t + 1 });
		}
	}

	cout << ans << '\n' << cnt;

	return 0;
}