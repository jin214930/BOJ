#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		getline(cin, s);
		if (s == ".")
			break;
		stack<char> st;

		for (char c : s) {
			if (c == '[' || c == '(')
				st.push(c);
			else if (c == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
					st.push(c);
			}
			else if (c == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					st.push(c);
			}
		}

		cout << (st.empty() ? "yes\n" : "no\n");
	}

	return 0;
}