#include <bits/stdc++.h>
using namespace std;

int n, m, t, x, d, k, a[51][51], visited[51][51], ans;
vector<pair<int, int>> v;

void rot(int x, int d, int k) {
  while (k--) {
    int tmp;
    if (d) {
      tmp = a[x][1];
      for (int i = 1; i < m; i++) a[x][i] = a[x][i + 1];
      a[x][m] = tmp;
    } else {
      tmp = a[x][m];
      for (int i = m; i > 1; i--) a[x][i] = a[x][i - 1];
      a[x][1] = tmp;
    }
  }
}

void dfs(int y, int x) {
  visited[y][x] = 1;
  v.push_back({y, x});

  for (int i : {-1, 1}) {
    int ny = y + i;
    if (ny > n || ny < 1) continue;
    if (visited[ny][x] || a[ny][x] != a[y][x]) continue;
    dfs(ny, x);
  }

  for (int i : {-1, 1}) {
    int nx = x + i;
    if (nx <= 0) nx += m;
    if (nx > m) nx -= m;
    if (visited[y][nx] || a[y][nx] != a[y][x]) continue;
    dfs(y, nx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tmp;
      cin >> tmp;
      a[i][j] = tmp;
    }
  }

  while (t--) {
    memset(visited, 0, sizeof(visited));
    cin >> x >> d >> k;
    for (int i = 1; i <= n; i++) {
      if (i % x == 0) rot(i, d, k);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!visited[i][j] && a[i][j]) {
          v.clear();
          dfs(i, j);
          if (v.size() >= 2) {
            for (auto i : v) a[i.first][i.second] = 0;
            flag = false;
          }
        }
      }
    }

    if (flag) {
      double sum = 0, cnt = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j]) {
            sum += a[i][j];
            cnt++;
          }
        }
      }
      sum /= cnt;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j]) {
            if (a[i][j] > sum)
              a[i][j]--;
            else if (a[i][j] < sum)
              a[i][j]++;
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) ans += a[i][j];
  }

  cout << ans;

  return 0;
}
