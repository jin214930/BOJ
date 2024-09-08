#include <bits/stdc++.h>
using namespace std;

long long n, ha, t, a, h, ans;
vector<tuple<long long, long long, long long>> v;

bool check(long long k) {
  long long curhp = k;
  long long cura = ha;
  for (auto i : v) {
    tie(t, a, h) = i;
    if (t == 2) {
      curhp = min(k, curhp + h);
      cura += a;
    } else {
      long long cnt = h / cura;
      if (h % cura) cnt++;
      if (curhp - a * (cnt - 1) <= 0) return false;
      curhp -= a * (cnt - 1);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> ha;
  for (int i = 0; i < n; i++) {
    cin >> t >> a >> h;
    v.push_back({t, a, h});
  }

  long long start = 1;
  long long end = 1e18;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (check(mid)) {
      ans = mid;
      end = mid - 1;
    } else
      start = mid + 1;
  }

  cout << ans;

  return 0;
}