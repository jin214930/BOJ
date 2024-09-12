#include <bits/stdc++.h>
using namespace std;

int n, m, r, a[300][300];

void go(int k) {
  if (k == min(n, m) / 2) return;

  int tmp = a[k][k];
  for (int i = k; i < m - k - 1; i++) a[k][i] = a[k][i + 1];
  for (int i = k; i < n - k - 1; i++) a[i][m - k - 1] = a[i + 1][m - k - 1];
  for (int i = m - k - 1; i > k; i--) a[n - k - 1][i] = a[n - k - 1][i - 1];
  for (int i = n - k - 1; i > k + 1; i--) a[i][k] = a[i - 1][k];
  a[k + 1][k] = tmp;
  go(k + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  for (int i = 0; i < r; i++) go(0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }

  return 0;
}