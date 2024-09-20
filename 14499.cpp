#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k, a[20][20], dice[6], d;
int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};

void roll(int d) {
  int tmp = dice[0];
  if (d == 0) {
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
  } else if (d == 1) {
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
  } else if (d == 2) {
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
  } else {
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> y >> x >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  dice[5] = a[y][x];
  a[y][x] = 0;

  while (k--) {
    cin >> d;
    d--;
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

    roll(d);

    if (a[ny][nx] == 0)
      a[ny][nx] = dice[5];
    else {
      dice[5] = a[ny][nx];
      a[ny][nx] = 0;
    }

    cout << dice[0] << '\n';

    y = ny;
    x = nx;
  }

  return 0;
}