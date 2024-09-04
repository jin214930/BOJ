#include <bits/stdc++.h>
using namespace std;

int r, c, t, a[50][50], b[50][50], ans, x;
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

void spread() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] > 0) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          if (ny >= 0 && nx >= 0 && ny < r && nx < c && a[ny][nx] != -1) {
            b[ny][nx] += a[i][j] / 5;
            cnt++;
          }
        }
        b[i][j] += a[i][j] - a[i][j] / 5 * cnt;
      } else if (a[i][j] == -1)
        b[i][j] = -1;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      a[i][j] = b[i][j];
      b[i][j] = 0;
    }
  }
}

void clean() {
  for (int i = x - 2; i > 0; i--) a[i][0] = a[i - 1][0];
  for (int i = 0; i < c - 1; i++) a[0][i] = a[0][i + 1];
  for (int i = 1; i <= x - 1; i++) a[i - 1][c - 1] = a[i][c - 1];
  for (int i = c - 1; i > 1; i--) a[x - 1][i] = a[x - 1][i - 1];
  a[x - 1][1] = 0;

  for (int i = x + 1; i < r - 1; i++) a[i][0] = a[i + 1][0];
  for (int i = 0; i < c - 1; i++) a[r - 1][i] = a[r - 1][i + 1];
  for (int i = r - 1; i >= x; i--) a[i][c - 1] = a[i - 1][c - 1];
  for (int i = c - 1; i > 1; i--) a[x][i] = a[x][i - 1];
  a[x][1] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c >> t;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] == -1) x = i;
    }
  }

  while (t--) {
    spread();
    clean();
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) ans += a[i][j];
  }

  cout << ans + 2;

  return 0;
}
