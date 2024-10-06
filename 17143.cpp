#include <bits/stdc++.h>
using namespace std;

struct Shark {
  int y, x, s, d, z, death;
} v[10001];
int r, c, m, ans, a[100][100], tmp[100][100];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, 1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i].y >> v[i].x >> v[i].s >> v[i].d >> v[i].z;
    v[i].y--;
    v[i].x--;
    v[i].d--;

    if (v[i].d <= 1)
      v[i].s %= 2 * (r - 1);
    else
      v[i].s %= 2 * (c - 1);

    a[v[i].y][v[i].x] = i;
  }

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      if (a[j][i]) {
        v[a[j][i]].death = 1;
        ans += v[a[j][i]].z;
        a[j][i] = 0;
        break;
      }
    }

    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= m; i++) {
      if (v[i].death) continue;
      int y = v[i].y;
      int x = v[i].x;
      int s = v[i].s;
      int d = v[i].d;

      int ny, nx;
      while (true) {
        ny = y + s * dy[d];
        nx = x + s * dx[d];
        if (ny >= 0 && nx >= 0 && ny < r && nx < c) break;
        if (d <= 1) {
          if (ny < 0) {
            s -= y;
            y = 0;
          } else {
            s -= r - 1 - y;
            y = r - 1;
          }
        } else {
          if (nx < 0) {
            s -= x;
            x = 0;
          } else {
            s -= c - 1 - x;
            x = c - 1;
          }
        }
        d ^= 1;
      }

      if (tmp[ny][nx]) {
        if (v[tmp[ny][nx]].z < v[i].z) {
          v[tmp[ny][nx]].death = 1;
          tmp[ny][nx] = i;
        } else
          v[i].death = 1;
      } else
        tmp[ny][nx] = i;

      v[i].y = ny;
      v[i].x = nx;
      v[i].d = d;
    }
    memcpy(a, tmp, sizeof(tmp));
  }

  cout << ans;

  return 0;
}
