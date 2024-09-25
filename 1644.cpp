#include <bits/stdc++.h>
using namespace std;

int n, p[4000001], a[4000001], ans, s, e, cnt, sum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  p[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!p[i]) {
      a[cnt++] = i;
      for (int j = i * 2; j <= n; j += i) p[j] = 1;
    }
  }

  while (true) {
    if (sum >= n)
      sum -= a[s++];
    else if (e == cnt)
      break;
    else
      sum += a[e++];
    if (sum == n) ans++;
  }

  cout << ans;

  return 0;
}