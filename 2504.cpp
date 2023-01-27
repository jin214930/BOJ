#include <bits/stdc++.h> 
using namespace std;

string s;
int ans, tmp = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> s;
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			tmp *= 2;
		}
		else if (s[i] == '[') {
			st.push(s[i]);
			tmp *= 3;
		}
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				if (s[i - 1] == '(')
					ans += tmp;
				tmp /= 2;
				st.pop();
			}
			else
				st.push(s[i]);
		}
		else {
			if (!st.empty() && st.top() == '[') {
				if (s[i - 1] == '[')
					ans += tmp;
				tmp /= 3;
				st.pop();
			}
			else
				st.push(s[i]);
		}
	}

	cout << (st.empty() ? ans : 0);
	
	return 0;
}