#include <bits/stdc++.h>
using namespace std;

string a[4];
int k, x, d, r[4], ans;

void rotate(int x, int d) {
  if (d == 1) {
    char tmp = a[x][7];
    for (int i = 7; i > 0; i--) a[x][i] = a[x][i - 1];
    a[x][0] = tmp;
  } else if (d == -1) {
    char tmp = a[x][0];
    for (int i = 0; i < 7; i++) a[x][i] = a[x][i + 1];
    a[x][7] = tmp;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 4; i++) cin >> a[i];
  cin >> k;

  while (k--) {
    memset(r, 0, sizeof(r));
    cin >> x >> d;
    x--;
    r[x] = d;
    for (int i = x; i > 0; i--) {
      if (a[i][6] != a[i - 1][2])
        r[i - 1] = -r[i];
      else
        break;
    }
    for (int i = x; i < 3; i++) {
      if (a[i][2] != a[i + 1][6])
        r[i + 1] = -r[i];
      else
        break;
    }

    for (int i = 0; i < 4; i++) rotate(i, r[i]);
  }

  int tmp = 1;
  for (int i = 0; i < 4; i++) {
    if (a[i][0] == '1') ans += tmp;
    tmp *= 2;
  }
  cout << ans;

  return 0;
}