#include <bits/stdc++.h>
using namespace std;

long long n, d[101][21], a[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  d[1][a[1]] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 21; j++) {
      if (j + a[i + 1] <= 20) d[i + 1][j + a[i + 1]] += d[i][j];
      if (j - a[i + 1] >= 0) d[i + 1][j - a[i + 1]] += d[i][j];
    }
  }

  cout << d[n - 1][a[n]];

  return 0;
}