#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k, a[20][20], dice[6] = {1, 2, 3, 4, 5, 6}, d, ans,
                              visited[20][20];
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int dfs(int y, int x) {
  int cnt = 1;
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (!visited[ny][nx] && a[ny][nx] == a[y][x]) cnt += dfs(ny, nx);
  }
  return cnt;
}

void roll(int d) {
  int tmp = dice[0];
  if (d == 0) {
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
  } else if (d == 1) {
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
  } else if (d == 2) {
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
  } else {
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  while (k--) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
      d = (d + 2) % 4;
      ny = y + dy[d];
      nx = x + dx[d];
    }

    roll(d);

    if (dice[5] > a[ny][nx])
      d = (d + 1) % 4;
    else if (dice[5] < a[ny][nx])
      d = (d + 3) % 4;

    memset(visited, 0, sizeof(visited));
    ans += dfs(ny, nx) * a[ny][nx];

    y = ny;
    x = nx;
  }

  cout << ans;

  return 0;
}