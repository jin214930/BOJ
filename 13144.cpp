#include <bits/stdc++.h>
using namespace std;

long long n, a[100001], cnt[1000001], ans, s, e;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  while (e < n) {
    if (!cnt[a[e]]) {
      cnt[a[e]]++;
      e++;
    } else {
      ans += e - s;
      cnt[a[s]]--;
      s++;
    }
  }

  ans += (e - s) * (e - s + 1) / 2;
  cout << ans;

  return 0;
}