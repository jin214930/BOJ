#include <bits/stdc++.h>
using namespace std;

string s, tmp;
int ans;
bool isMinus;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (isMinus)
				ans -= atoi(tmp.c_str());
			else
				ans += atoi(tmp.c_str());
			tmp = "";
		}
		else 
			tmp += s[i];
		if (s[i] == '-')
			isMinus = true;
	}

	cout << ans;

	return 0;
}