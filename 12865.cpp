#include <bits/stdc++.h>
using namespace std;

int n, k, w[101], v[101], d[101][100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (w[j] > i)
        d[j][i] = d[j - 1][i];
      else
        d[j][i] = max(d[j - 1][i - w[j]] + v[j], d[j - 1][i]);
    }
  }

  cout << d[n][k];

  return 0;
}