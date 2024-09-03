#include <bits/stdc++.h>
using namespace std;

int n, m, h, x, y, a[32][12], ans = 4;

bool check() {
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    for (int j = 1; j <= h; j++) {
      if (a[j][tmp])
        tmp++;
      else if (a[j][tmp - 1])
        tmp--;
    }
    if (tmp != i) return false;
  }
  return true;
}

void go(int cnt, int idx) {
  if (cnt >= ans) return;

  if (check()) {
    ans = min(ans, cnt);
    return;
  }

  for (int i = idx; i <= h; i++) {
    for (int j = 1; j <= n; j++) {
      if (!a[i][j] && !a[i][j - 1] && !a[i][j + 1]) {
        a[i][j] = 1;
        go(cnt + 1, i);
        a[i][j] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    a[x][y] = 1;
  }

  go(0, 1);

  if (ans == 4) {
    cout << -1;
    return 0;
  }
  cout << ans;

  return 0;
}