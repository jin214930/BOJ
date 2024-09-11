#include <bits/stdc++.h>
using namespace std;

int n, m, visited[50][50];
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
char a[50][50];
bool flag;

void dfs(int y, int x, int cnt) {
  if (flag) return;
  visited[y][x] = cnt;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] == a[y][x]) {
      if (!visited[ny][nx])
        dfs(ny, nx, cnt + 1);
      else {
        if (cnt >= 4 && visited[ny][nx] != cnt - 1) {
          flag = true;
          return;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!flag && !visited[i][j]) {
        dfs(i, j, 1);
      }
    }
  }

  cout << (flag ? "Yes" : "No");

  return 0;
}