#include <bits/stdc++.h>
using namespace std;

int h, w, a[103][103];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '.')
				a[i][j] = -1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0) {
				while (a[i][j + 1] == -1) {
					a[i][j + 1] = a[i][j] + 1;
					j++;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}