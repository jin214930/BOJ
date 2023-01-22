#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 999999999;
vector<pair<int, int>> c, h;
vector<vector<int>> cs;

void combi(int start, vector<int> b) {
	if (b.size() == m) {
		cs.push_back(b);
		return;
	}
	for (int i = start + 1; i < c.size(); i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 2)
				c.push_back({ i, j });
			else if (tmp == 1)
				h.push_back({ i, j });
		}
	}

	vector<int> v;
	combi(-1, v);

	for (auto i : cs) {
		int ret = 0;
		for (auto j : h) {
			int _min = 999999999;
			for (auto k : i) {
				int d = abs(j.first - c[k].first) + abs(j.second - c[k].second);
				_min = min(_min, d);
			}
			ret += _min;
		}
		ans = min(ret, ans);
	}

	cout << ans;

	return 0;
}
