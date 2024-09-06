#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], visited[50][50], ans1, ans2, ans3;
int dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0};
vector<int> v;

int dfs(int y, int x) {
  visited[y][x] = ans1;

  int tmp = 1;
  for (int i = 0; i < 4; i++) {
    if (a[y][x] & (1 << i)) continue;
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx])
      tmp += dfs(ny, nx);
  }

  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        ans1++;
        int tmp = dfs(i, j);
        v.push_back(tmp);
        ans2 = max(ans2, tmp);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i != n - 1 && visited[i][j] != visited[i + 1][j])
        ans3 = max(ans3, v[visited[i][j] - 1] + v[visited[i + 1][j] - 1]);
      if (j != m - 1 && visited[i][j] != visited[i][j + 1])
        ans3 = max(ans3, v[visited[i][j] - 1] + v[visited[i][j + 1] - 1]);
    }
  }

  cout << ans1 << '\n' << ans2 << '\n' << ans3;

  return 0;
}