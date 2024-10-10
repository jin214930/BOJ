#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000][1000], y, x, ansy, ansx, d;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  y = n / 2;
  x = n / 2;
  for (int i = 1; i <= n * n; i++) {
    a[y][x] = i;
    if (i == k) {
      ansy = y;
      ansx = x;
    }
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (a[ny][nx]) {
      d = (d + 3) % 4;
      ny = y + dy[d];
      nx = x + dx[d];
    }
    y = ny;
    x = nx;
    d = (d + 1) % 4;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
  cout << ansy + 1 << ' ' << ansx + 1;

  return 0;
}