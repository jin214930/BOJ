#include <bits/stdc++.h> 
using namespace std;

int n, a[11], op[4], ans1 = -999999999, ans2 = 999999999;

void go(int ret, int idx) {
	if (idx == n) {
		ans1 = max(ans1, ret);
		ans2 = min(ans2, ret);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0)
				go(ret + a[idx], idx + 1);
			else if (i == 1)
				go(ret - a[idx], idx + 1);
			else if (i == 2)
				go(ret * a[idx], idx + 1);
			else
				go(ret / a[idx], idx + 1);
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	
	go(a[0], 1);

	cout << ans1 << '\n' << ans2;	

	return 0;
}