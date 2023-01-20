#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> v(n), ans(n, -1);
	stack<int> st;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++) {
		while (!st.empty() && v[st.top()] < v[i]) {
			ans[st.top()] = v[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	return 0;
}