#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	while (n--) {
		cin >> s;
		stack<char> st;

		for (char c : s) {
			if (!st.empty() && st.top() == c)
				st.pop();
			else
				st.push(c);
		}

		if (st.empty())
			ans++;
	}

	cout << ans;

	return 0;
}