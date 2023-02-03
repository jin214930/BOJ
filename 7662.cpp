#include <bits/stdc++.h> 
using namespace std;

int t, k, n;
char cmd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> k;
		multiset<int> ms;
		for (int i = 0; i < k; i++) {
			cin >> cmd >> n;
			if (cmd == 'I') 
				ms.insert(n);
			else {
				if (ms.size()) {
					if (n == -1)
						ms.erase(ms.begin());

					else
						ms.erase(--ms.end());
				}
			}
		}
		if (ms.size()) {
			cout << *(--ms.end()) << ' ' << *(ms.begin()) << '\n';
		}
		else
			cout << "EMPTY\n";
	}

	return 0;
}