#include <bits/stdc++.h>
using namespace std;

int n, ans = 999999999, a[100000], b[100000];

void go(int x, int y, int cnt) {
  for (int i = 0; i < n; i++) b[i] = a[i];
  b[0] = x;
  b[1] = y;
  int tmp = x - y;

  for (int i = 2; i < n; i++) {
    if (abs(b[i - 1] - b[i] - tmp) >= 2) {
      cnt = 999999999;
      break;
    } else if (b[i - 1] - b[i] - 1 == tmp) {
      b[i]++;
      cnt++;
    } else if (b[i - 1] - b[i] + 1 == tmp) {
      b[i]--;
      cnt++;
    }
  }

  ans = min(ans, cnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  if (n <= 2) {
    cout << 0;
    return 0;
  }

  go(a[0] - 1, a[1] - 1, 2);
  go(a[0], a[1] - 1, 1);
  go(a[0] + 1, a[1] - 1, 2);
  go(a[0] - 1, a[1], 1);
  go(a[0], a[1], 0);
  go(a[0] + 1, a[1], 1);
  go(a[0] - 1, a[1] + 1, 2);
  go(a[0], a[1] + 1, 1);
  go(a[0] + 1, a[1] + 1, 2);

  if (ans == 999999999)
    cout << -1;
  else
    cout << ans;

  return 0;
}