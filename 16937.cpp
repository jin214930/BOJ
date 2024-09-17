#include <bits/stdc++.h>
using namespace std;

int h, w, n, r, c, ans;
vector<pair<int, int>> v;

bool check(int a, int b) {
  if (v[a].first + v[b].first <= h && max(v[a].second, v[b].second) <= w)
    return true;
  if (v[a].second + v[b].second <= w && max(v[a].first, v[b].first) <= h)
    return true;
  if (v[a].first + v[b].first <= w && max(v[a].second, v[b].second) <= h)
    return true;
  if (v[a].second + v[b].second <= h && max(v[a].first, v[b].first) <= w)
    return true;
  if (v[a].first + v[b].second <= h && max(v[a].second, v[b].first) <= w)
    return true;
  if (v[a].second + v[b].first <= w && max(v[a].first, v[b].second) <= h)
    return true;
  if (v[a].first + v[b].second <= w && max(v[a].second, v[b].first) <= h)
    return true;
  if (v[a].second + v[b].first <= h && max(v[a].first, v[b].second) <= w)
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w >> n;
  for (int i = 0; i < n; i++) {
    cin >> r >> c;
    v.push_back({r, c});
  }

  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (check(i, j))
        ans = max(ans, v[i].first * v[i].second + v[j].first * v[j].second);
    }
  }

  cout << ans;

  return 0;
}