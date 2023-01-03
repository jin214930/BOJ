#include <bits/stdc++.h>
using namespace std;

int arr[9], sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			if (arr[i] + arr[j] == sum - 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << arr[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}