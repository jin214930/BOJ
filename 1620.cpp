#include <bits/stdc++.h>
using namespace std;

int n, m, tmp;
string s;
map<string, int> mp;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s] = i + 1;
		v.push_back(s);
	}

	while (m--) {
		cin >> s;
		if ((tmp = atoi(s.c_str())) == 0)
			cout << mp[s] << '\n';
		else
			cout << v[tmp - 1] << '\n';
	}

	return 0;
}