#include <bits/stdc++.h>
using namespace std;

int n, a[20][20], visited[20][20], s = 2, cnt, ans, sy, sx;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = 1;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if (visited[ny][nx] || a[ny][nx] > s) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 9) {
        a[i][j] = 0;
        sy = i;
        sx = j;
      }
    }
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    bfs(sy, sx);

    int mn = 999999999;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] && a[i][j] && a[i][j] < s && visited[i][j] < mn) {
          mn = visited[i][j];
          sy = i;
          sx = j;
        }
      }
    }

    if (mn == 999999999) break;

    a[sy][sx] = 0;
    cnt++;
    ans += visited[sy][sx] - 1;
    if (cnt == s) {
      cnt = 0;
      s++;
    }
  }

  cout << ans;

  return 0;
}