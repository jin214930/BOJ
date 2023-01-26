#include <bits/stdc++.h> 
using namespace std;

int n, a[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	stack<int> st;
	for (int i = 1; i <= n; i++) {
		if (st.empty()) 
			cout << 0 << ' ';
		else {
			if (a[st.top()] >= a[i]) 
				cout << st.top() << ' ';
			else {
				while (st.size()) {
					if (a[st.top()] >= a[i]) {
						cout << st.top() << ' ';
						break;
					}
					st.pop();
				}
				if (st.empty())
					cout << 0 << ' ';
			}
		}
		st.push(i);
	}
	
	return 0;
}