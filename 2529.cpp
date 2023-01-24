#include <bits/stdc++.h> 
using namespace std;

char a[10];
int k, check[10];
vector<string> ans;

bool ok(char a, char b, char op) {
	if (op == '<')
		return a < b;
	else
		return a > b;
}

void go(int n, string s) {
	if (n == k + 1) {
		ans.push_back(s);
		return;
	}
	for (char i = 0; i <= 9; i++) {
		if (check[i])
			continue;
		if (n == 0 || ok(s[n - 1], i + '0', a[n - 1])) {
			check[i] = 1;
			go(n + 1, s + to_string(i));
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> a[i];

	go(0, "");

	cout << *max_element(ans.begin(), ans.end()) << '\n' << *min_element(ans.begin(), ans.end());

	return 0;
}