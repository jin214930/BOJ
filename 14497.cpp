#include <bits/stdc++.h>
using namespace std;

int n, m, b, c, d, e, visited[300][300];
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
char a[300][300];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> b >> c >> d >> e;
  b--;
  c--;
  d--;
  e--;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  queue<pair<int, int>> q;
  q.push({b, c});
  visited[b][c] = 1;
  int cnt = 0;

  while (a[d][e] != '0') {
    cnt++;
    queue<pair<int, int>> tmp;
    while (q.size()) {
      int y, x;
      tie(y, x) = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx]) {
          if (a[ny][nx] == '0')
            q.push({ny, nx});
          else {
            tmp.push({ny, nx});
            a[ny][nx] = '0';
          }
          visited[ny][nx] = cnt;
        }
      }
    }
    q = tmp;
  }

  cout << visited[d][e];

  return 0;
}