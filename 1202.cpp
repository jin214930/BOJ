#include <bits/stdc++.h>
using namespace std;

int n, k, m, v, c;
long long ans;
vector<pair<int, int>> j;
vector<int> b;
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> m >> v;
    j.push_back({m, v});
  }
  for (int i = 0; i < k; i++) {
    cin >> c;
    b.push_back(c);
  }

  sort(j.begin(), j.end());
  sort(b.begin(), b.end());

  int idx = 0;

  for (int i = 0; i < k; i++) {
    while (j[idx].first <= b[i] && idx < n) {
      pq.push(j[idx].second);
      idx++;
    }
    if (pq.size()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans;

  return 0;
}