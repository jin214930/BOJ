#include <bits/stdc++.h> 
using namespace std;

int k, tmp;
vector<int> a, v[15];

void go(int start, int size, int level) {
	if (size == 1) {
		v[level].push_back(a[start]);
		return;
	}
	v[level].push_back(a[start + size / 2]);
	go(start, size / 2, level + 1);
	go(start + size / 2 + 1, size / 2, level + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> k;

	int size = (int)pow(2, k) - 1;
	for (int i = 0; i < size; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	go(0, size, 1);

	for (int i = 1; i <= k; i++) {
		for (int j : v[i])
			cout << j << ' ';
		cout << '\n';
	}

	return 0;
}