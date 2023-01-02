#include <bits/stdc++.h>
using namespace std;

int n, k, arr[500004], tmp[500004], cnt = 0, ans = -1;

void merge(int start, int mid, int end) {
	int i = start, j = mid + 1, t = 1;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])
			tmp[t++] = arr[i++];
		else
			tmp[t++] = arr[j++];
	}

	while (i <= mid)
		tmp[t++] = arr[i++];

	while (j <= end)
		tmp[t++] = arr[j++];

	i = start, t = 1;

	while (i <= end) {
		arr[i++] = tmp[t++];
		cnt++;
		if (cnt == k) {
			ans = arr[i - 1];
			return;
		}
	}
}

void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(0, n - 1);
	cout << ans;

	return 0;
}