#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
deque<int> a, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < 2 * n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
    r.push_back(0);
  }

  while (true) {
    ans++;

    a.push_front(a.back());
    a.pop_back();
    r.push_front(r.back());
    r.pop_back();
    r[n - 1] = 0;

    for (int i = n - 1; i >= 0; i--) {
      if (r[i] && !r[i + 1] && a[i + 1]) {
        r[i] = 0;
        r[i + 1] = 1;
        a[i + 1]--;
      }
    }
    r[n - 1] = 0;

    if (a[0]) {
      a[0]--;
      r[0] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
      if (!a[i]) cnt++;
    }
    if (cnt >= k) break;
  }

  cout << ans;

  return 0;
}