#include <bits/stdc++.h>
using namespace std;

int n, m, ans, visited[100][100], y, x, d;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n * m - 1; i++) {
    visited[y][x] = 1;
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) {
      ans++;
      d = (d + 1) % 4;
      ny = y + dy[d];
      nx = x + dx[d];
    }
    y = ny;
    x = nx;
  }

  cout << ans;

  return 0;
}
