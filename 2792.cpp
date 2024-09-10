#include <bits/stdc++.h>
using namespace std;

int n, m, a[300000], ans;

bool check(int k) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += a[i] / k;
    if (a[i] % k) cnt++;
  }
  return cnt <= n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);

  int start = 1;
  int end = a[m - 1];
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