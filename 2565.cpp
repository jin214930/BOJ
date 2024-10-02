#include <bits/stdc++.h>
using namespace std;

int n, ans, d[101];
vector<pair<int, int>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    d[i] = 1;
    for (int j = 0; j < i; j++) {
      if (v[i].second > v[j].second) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
    ans = max(ans, d[i]);
  }

  cout << n - ans;

  return 0;
}