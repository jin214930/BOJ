#include <bits/stdc++.h> 
using namespace std;

int n, ans = - 999999999;
string s;
vector<int> num;
vector<char> op;

int eval(char op, int a, int b) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else
		return a * b;
}

void go(int cnt, int k) {
	if (cnt == num.size() - 1) {
		ans = max(ans, k);
		return;
	}
	go(cnt + 1, eval(op[cnt], k, num[cnt + 1]));
	if (cnt + 2 <= num.size() - 1) {
		int tmp = eval(op[cnt + 1], num[cnt + 1], num[cnt + 2]);
		go(cnt + 2, eval(op[cnt], k, tmp));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			num.push_back(s[i] - '0');
		else
			op.push_back(s[i]);
	}

	go(0, num[0]);

	cout << ans;

	return 0;
}