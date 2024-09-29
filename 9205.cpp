#include <bits/stdc++.h>
using namespace std;

int t, n, sy, sx, ey, ex, y, x, visited[100];
vector<pair<int, int>> v;

bool bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});

  while (q.size()) {
    tie(x, y) = q.front();
    q.pop();

    if (abs(ex - x) + abs(ey - y) <= 1000) return true;

    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      if (abs(v[i].first - x) + abs(v[i].second - y) <= 1000) {
        visited[i] = 1;
        q.push(v[i]);
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    memset(visited, 0, sizeof(visited));
    v.clear();
    cin >> n;
    cin >> sx >> sy;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      v.push_back({x, y});
    }
    cin >> ex >> ey;

    bool flag = bfs(sx, sy);

    cout << (flag ? "happy" : "sad") << '\n';
  }

  return 0;
}