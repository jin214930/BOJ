#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		stack<char> st;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				st.push(s[i]);
			else {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					st.push(s[i]);
			}
		}

		cout << (st.empty() ? "YES\n" : "NO\n");
	}

	return 0;
}