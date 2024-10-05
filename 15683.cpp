#include <bits/stdc++.h>
using namespace std;

int n, m, a[8][8], ans = 999999999;

int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

vector<pair<int, int>> cctv(int idx, int d) {
  vector<pair<int, int>> tmp;
  int y = v[idx].first;
  int x = v[idx].second;
  if (a[y][x] == 1) {
    while (true) {
      int ny = y + dy[d];
      int nx = x + dx[d];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
      if (a[ny][nx] == 0) {
        a[ny][nx] = 7;
        tmp.push_back({ny, nx});
      }
      y = ny;
      x = nx;
    }
  } else if (a[y][x] == 2) {
    for (int i = 0; i <= 2; i += 2) {
      int tmpy = y;
      int tmpx = x;
      while (true) {
        int ny = tmpy + dy[(d + i) % 4];
        int nx = tmpx + dx[(d + i) % 4];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
        if (a[ny][nx] == 0) {
          a[ny][nx] = 7;
          tmp.push_back({ny, nx});
        }
        tmpy = ny;
        tmpx = nx;
      }
    }
  } else if (a[y][x] == 3) {
    for (int i = 0; i < 2; i++) {
      int tmpy = y;
      int tmpx = x;
      while (true) {
        int ny = tmpy + dy[(d + i) % 4];
        int nx = tmpx + dx[(d + i) % 4];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
        if (a[ny][nx] == 0) {
          a[ny][nx] = 7;
          tmp.push_back({ny, nx});
        }
        tmpy = ny;
        tmpx = nx;
      }
    }
  } else if (a[y][x] == 4) {
    for (int i = 0; i < 3; i++) {
      int tmpy = y;
      int tmpx = x;
      while (true) {
        int ny = tmpy + dy[(d + i) % 4];
        int nx = tmpx + dx[(d + i) % 4];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
        if (a[ny][nx] == 0) {
          a[ny][nx] = 7;
          tmp.push_back({ny, nx});
        }
        tmpy = ny;
        tmpx = nx;
      }
    }
  } else if (a[y][x] == 5) {
    for (int i = 0; i < 4; i++) {
      int tmpy = y;
      int tmpx = x;
      while (true) {
        int ny = tmpy + dy[(d + i) % 4];
        int nx = tmpx + dx[(d + i) % 4];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
        if (a[ny][nx] == 0) {
          a[ny][nx] = 7;
          tmp.push_back({ny, nx});
        }
        tmpy = ny;
        tmpx = nx;
      }
    }
  }

  return tmp;
}

void go(int idx) {
  if (idx == v.size()) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!a[i][j]) cnt++;
      }
    }
    ans = min(cnt, ans);
    return;
  }

  for (int i = 0; i < 4; i++) {
    vector<pair<int, int>> tmp = cctv(idx, i);
    go(idx + 1);
    for (auto j : tmp) a[j.first][j.second] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] && a[i][j] != 6) v.push_back({i, j});
    }
  }

  go(0);

  cout << ans;

  return 0;
}
