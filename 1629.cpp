#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long go(long long n, long long k) {
	if (k == 1)
		return n % c;

	long long ret = go(n, k / 2);
	ret = ret * ret % c;

	if (k % 2 == 1)
		ret = ret * a % c;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	cout << go(a, b);

	return 0;
}