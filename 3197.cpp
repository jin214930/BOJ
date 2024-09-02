#include <bits/stdc++.h>
using namespace std;

int n, m, visited1[1500][1500], visited2[1500][1500], cnt, sy, sx, y, x;
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
char a[1500][1500];
queue<pair<int, int>> q1, q2, tmp1, tmp2;

bool check() {
  while (q2.size()) {
    tie(y, x) = q2.front();
    q2.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited2[ny][nx]) {
        if (a[ny][nx] == '.')
          q2.push({ny, nx});
        else if (a[ny][nx] == 'X')
          tmp2.push({ny, nx});
        else if (a[ny][nx] == 'L')
          return true;
        visited2[ny][nx] = 1;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'L') {
        sy = i;
        sx = j;
      }
      if (a[i][j] == '.' || a[i][j] == 'L') {
        q1.push({i, j});
        visited1[i][j] = 1;
      }
    }
  }

  q2.push({sy, sx});
  visited2[sy][sx] = 1;

  while (true) {
    if (check()) {
      cout << cnt;
      break;
    }
    q2 = tmp2;
    cnt++;
    while (q1.size()) {
      tie(y, x) = q1.front();
      q1.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited1[ny][nx]) {
          if (a[ny][nx] == 'X') {
            a[ny][nx] = '.';
            tmp1.push({ny, nx});
            visited1[ny][nx] = 1;
          }
        }
      }
    }
    q1 = tmp1;

    while (tmp1.size()) tmp1.pop();
    while (tmp2.size()) tmp2.pop();
  }

  return 0;
}