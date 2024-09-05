#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c, s, a[51][51], b[51][51], ans = 999999999;
vector<tuple<int, int, int>> v;

void rot(int r, int c, int s) {
  if (s == 0) return;

  int tmp = a[r - s][c - s];
  for (int i = r - s; i < r + s; i++) a[i][c - s] = a[i + 1][c - s];
  for (int i = c - s; i < c + s; i++) a[r + s][i] = a[r + s][i + 1];
  for (int i = r + s; i > r - s; i--) a[i][c + s] = a[i - 1][c + s];
  for (int i = c + s; i > c - s + 1; i--) a[r - s][i] = a[r - s][i - 1];
  a[r - s][c - s + 1] = tmp;
  rot(r, c, s - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      b[i][j] = a[i][j];
    }
  }

  while (k--) {
    cin >> r >> c >> s;
    v.push_back({r, c, s});
  }

  sort(v.begin(), v.end());
  do {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) a[i][j] = b[i][j];
    }

    for (int i = 0; i < v.size(); i++) {
      tie(r, c, s) = v[i];
      rot(r, c, s);
    }

    for (int i = 1; i <= n; i++) {
      int tmp = 0;
      for (int j = 1; j <= m; j++) tmp += a[i][j];
      ans = min(ans, tmp);
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << ans;

  return 0;
}