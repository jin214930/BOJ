#include <bits/stdc++.h> 
using namespace std;

int n, m, cnt, ans, idx;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> m >> s;

	while (idx <= m - 3) {
		if (s[idx] == 'I') {
			if (s[idx + 1] == 'O' && s[idx + 2] == 'I') {
				cnt++;
				idx = idx + 2;
			}
			else {
				if (cnt >= n)
					ans += cnt - n + 1;
				cnt = 0;
				idx++;
			}
		}
		else
			idx++;
	}

	if (cnt >= n)
		ans += cnt - n + 1;

	cout << ans;

	return 0;
}