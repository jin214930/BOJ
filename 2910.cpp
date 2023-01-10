#include <bits/stdc++.h>
using namespace std;

int n, c, cnt = INT_MAX;
map<int, pair<int, int>> mp;
vector<int> v;

bool cmp(int a, int b) {
	return mp[a] > mp[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		mp[tmp].first++;
		if (mp[tmp].second == 0) {
			mp[tmp].second = cnt;
			cnt--;
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i : v)
		cout << i << ' ';

	return 0;
}