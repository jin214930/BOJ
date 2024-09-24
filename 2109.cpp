#include <bits/stdc++.h>
using namespace std;

int n, p, d;
int ans;
vector<int> v[200001];
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d >> p;
    v[d].push_back(p);
  }

  for (int i = n; i >= 1; i--) {
    if (v[i].size()) {
      for (int j : v[i]) pq.push(j);
    }
    if (pq.size()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans;

  return 0;
}