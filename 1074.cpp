#include <bits/stdc++.h> 
using namespace std;

int n, r, c;

long long go(int s) {
	if (s == 2) {
		return r * 2 + c;
	}
	if (r < s / 2 && c < s / 2)
		return go(s / 2);
	else if (r < s / 2 && c >= s / 2) {
		c -= s / 2;
		return go(s / 2) + (s / 2) * (s / 2);
	}
	else if (r >= s / 2 && c < s / 2) {
		r -= s / 2;
		return go(s / 2) + (s / 2) * (s / 2) * 2;
	}
	else {
		c -= s / 2;
		r -= s / 2;
		return go(s / 2) + (s / 2) * (s / 2) * 3;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> r >> c;
	
	cout << go(pow(2, n));

	return 0;
}