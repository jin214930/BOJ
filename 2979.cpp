#include <bits/stdc++.h>
using namespace std;

int a[4], p, q, ans, cnt[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a[1] >> a[2] >> a[3];

	for (int i = 0; i < 3; i++) {
		cin >> p >> q;
		for (int j = p; j < q; j++)
			cnt[j]++;
	}

	for (int i : cnt) 
		ans += i * a[i];
	
	cout << ans;

	return 0;
}