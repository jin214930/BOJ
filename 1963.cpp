#include <bits/stdc++.h> 
using namespace std;

int t, a, b, x, visited[9000], prime[10000];
vector<int> v;

void go(int x) {
	string s = to_string(x);
	string tmp = s;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			tmp[i] = j + '0';
			int n = stoi(tmp.c_str());
			if (n >= 1000 && prime[n])
				v.push_back(n);
			tmp = s;
		}
	}
	
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i < 10000; i++) 
		prime[i] = 1;
	for (int i = 2; i < 10000; i++) {
		if (prime[i]) {
			for (int j = i + 1; j < 10000; j++)
				if (j % i == 0)
					prime[j] = 0;
		}
	}

	for (int i : v)
		cout << i << ' ';

	cin >> t;
	while (t--) {
		cin >> a >> b;
			
		queue<int> q;
		memset(visited, 0, sizeof(visited));
		q.push(a);
		visited[a - 1000] = 1;
		while (q.size()) {
			x = q.front();
			q.pop();
			go(x);
			for (int i : v) {
				if (!visited[i - 1000]) {
					q.push(i);
					visited[i - 1000] = visited[x - 1000] + 1;
				}
			}
			v.clear();
		}

		if (visited[b - 1000])
			cout << visited[b - 1000] - 1;
		else
			cout << "Impossible\n";
	}

	return 0;
}