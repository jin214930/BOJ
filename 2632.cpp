#include <bits/stdc++.h>
using namespace std;

int n, m, x, a[1001], b[1001], psum_a[2002], psum_b[2002], ans;
map<int, int> cnta, cntb;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum_a[i] = psum_a[i - 1] + a[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) psum_a[i] = psum_a[i - 1] + a[i - n];

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    psum_b[i] = psum_b[i - 1] + b[i];
  }
  for (int i = m + 1; i <= 2 * m; i++) psum_b[i] = psum_b[i - 1] + b[i - m];

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n + i - 1; j++) {
      int sum = psum_a[j] - psum_a[j - i];
      cnta[sum]++;
      if (i == n) break;
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m + i - 1; j++) {
      int sum = psum_b[j] - psum_b[j - i];
      cntb[sum]++;
      if (i == m) break;
    }
  }

  ans += cnta[x] + cntb[x];
  for (int i = 1; i < x; i++) ans += cnta[i] * cntb[x - i];
  cout << ans;

  return 0;
}
