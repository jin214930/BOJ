#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], visited[50][50], ans = 999999999;
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
vector<pair<int, int>> v;

void go(int idx, vector<int> tmp) {
  if (tmp.size() == m) {
    memset(visited, 0, sizeof(visited));
    int mx = 0;
    queue<pair<int, int>> q;
    for (int i : tmp) {
      q.push(v[i]);
      visited[v[i].first][v[i].second] = 1;
    }

    while (q.size()) {
      int y, x;
      tie(y, x) = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] || a[ny][nx] == 1) continue;
        q.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] != 1 && !visited[i][j]) return;
        mx = max(mx, visited[i][j]);
      }
    }

    ans = min(mx, ans);

    return;
  }

  for (int i = idx; i < v.size(); i++) {
    tmp.push_back(i);
    go(i + 1, tmp);
    tmp.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2) v.push_back({i, j});
    }
  }

  vector<int> tmp;
  go(0, tmp);

  if (ans == 999999999)
    cout << -1;
  else
    cout << ans - 1;

  return 0;
}