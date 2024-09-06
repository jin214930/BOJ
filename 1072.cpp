#include <bits/stdc++.h>
using namespace std;

long long x, y, z, ans = 1000000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x >> y;
  z = y * 100 / x;

  if (z >= 99) {
    cout << -1;
    return 0;
  }

  long long start = 1;
  long long end = 1000000000;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if ((y + mid) * 100 / (x + mid) >= z + 1) {
      end = mid - 1;
      ans = mid;
    } else
      start = mid + 1;
  }

  cout << ans;

  return 0;
}