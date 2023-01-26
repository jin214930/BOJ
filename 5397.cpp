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
		stack<char> st1, st2;
		cin >> s;
		for (char c : s) {
			if (c == '<') {
				if (st1.size()) {
					st2.push(st1.top());
					st1.pop();
				}
			}
			else if (c == '>') {
				if (st2.size()) {
					st1.push(st2.top());
					st2.pop();
				}
			}
			else if (c == '-') {
				if (st1.size())
					st1.pop();
			}
			else
				st1.push(c);
		}

		while (st1.size()) {
			st2.push(st1.top());
			st1.pop();
		}

		while (st2.size()) {
			cout << st2.top();
			st2.pop();
		}
		cout << '\n';
	}

	return 0;
}