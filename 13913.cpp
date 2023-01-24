#include <bits/stdc++.h> 
using namespace std;

int n, k, visited[100001], x;
vector<int> tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> k;
	vector<int> v;
	queue<pair<int, vector<int>>> q;
	v.push_back(n);
	q.push({ n, v });
	visited[n] = 1;

	while (q.size()) {
		tie(x, tmp) = q.front();
		q.pop();

		if (x == k) {
			v = tmp;
			break;
		}

		for (int i : {x - 1, x + 1, 2 * x}) {
			if (i >= 0 && i <= 100000 && !visited[i]) {
				tmp.push_back(i);
				q.push({ i, tmp });
				visited[i] = visited[x] + 1;
				tmp.pop_back();
			}
			
		}
	}

	cout << visited[k] - 1 << '\n';
	for (int i : v)
		cout << i << ' ';

	return 0;
}