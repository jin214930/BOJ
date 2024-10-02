#include <bits/stdc++.h>
using namespace std;

int n, x, mx, cnt = -1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    cin >> x;
    if (mx < x) {
      mx = x;
      cnt = i;
    }
  }

  cout << mx << ' ' << cnt + 1;

  return 0;
}