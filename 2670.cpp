#include <bits/stdc++.h>
using namespace std;

int n;
double a[10001], d[10001], ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  d[1] = a[1];
  for (int i = 2; i <= n; i++) {
    d[i] = max(a[i], d[i - 1] * a[i]);
    ans = max(ans, d[i]);
  }

  cout << fixed;
  cout.precision(3);
  cout << ans;

  return 0;
}