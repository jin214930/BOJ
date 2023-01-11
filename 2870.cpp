#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> v;

bool cmp(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;
		s += ' ';
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9')
				tmp += s[i];
			else {
				if (tmp != "") {
					while (tmp.size() != 0 && tmp.front() == '0') {
						tmp.erase(tmp.begin());
					}
					if (tmp == "")
						tmp = "0";
					v.push_back(tmp);
					tmp = "";
				}
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (string s : v)
		cout << s << '\n';

	return 0;
}