#include <bits/stdc++.h>
using namespace std;

int n, x;

struct cmp {
	bool operator() (int a, int b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) == abs(b)) {
			if (a > b)
				return true;
			else
				return false;
		}
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	priority_queue<int, vector<int>, cmp> pq;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
			pq.push(x);
	}

	return 0;
}