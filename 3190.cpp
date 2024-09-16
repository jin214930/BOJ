#include <bits/stdc++.h>
using namespace std;

int n, k, l, a[100][100], visited[100][100], y, x, ans;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
map<int, char> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> y >> x;
    y--;
    x--;
    a[y][x] = 1;
  }
  cin >> l;
  for (int i = 0; i < l; i++) {
    char c;
    cin >> x >> c;
    mp[x] = c;
  }

  int d = 0;
  deque<pair<int, int>> dq;
  dq.push_back({0, 0});
  visited[0][0] = 1;
  while (true) {
    ans++;
    tie(y, x) = dq.front();
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;
    if (a[ny][nx])
      a[ny][nx] = 0;
    else {
      visited[dq.back().first][dq.back().second] = 0;
      dq.pop_back();
    }
    visited[ny][nx] = 1;
    dq.push_front({ny, nx});

    if (mp[ans] == 'D') {
      d++;
      if (d >= 4) d -= 4;
    } else if (mp[ans] == 'L') {
      d--;
      if (d < 0) d += 4;
    }
  }

  cout << ans;

  return 0;
}