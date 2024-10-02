#include <bits/stdc++.h>
using namespace std;

int n, k, x, a[100], b[101], ans;
set<int> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> a[i];

  for (int i = 0; i < k; i++) {
    memset(b, 0, sizeof(b));
    if (s.size() == n && s.find(a[i]) == s.end()) {
      ans++;
      for (auto j : s) b[j] = 1000;
      for (int j = i + 1; j < k; j++) {
        if (j < b[a[j]]) b[a[j]] = j;
      }

      int mx = -1, tmp;
      for (auto j : s) {
        if (mx < b[j]) {
          tmp = j;
          mx = b[j];
        }
      }
      s.erase(s.find(tmp));
    }
    s.insert(a[i]);
  }

  cout << ans;

  return 0;
}