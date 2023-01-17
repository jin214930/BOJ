#include <bits/stdc++.h>
using namespace std;

int n, a[101][101], d[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			d[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (d[j][i] && d[i][k])
					d[j][k] = 1;
			}
		}
	}
	
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << d[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}