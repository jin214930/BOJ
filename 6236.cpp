#include <bits/stdc++.h>
using namespace std;

int n, m, a[100000], ans;

bool check(int k) {
  int tmp = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > k) return false;
    if (tmp < a[i]) {
      tmp = k;
      cnt++;
    }
    tmp -= a[i];
  }

  return cnt <= m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];

  int start = 1;
  int end = 1000000000;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (check(mid)) {
      ans = mid;
      end = mid - 1;
    } else
      start = mid + 1;
  }

  cout << ans;

  return 0;
}