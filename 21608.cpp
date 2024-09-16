#include <bits/stdc++.h>
using namespace std;

int n, x, a[20][20], s[5], ans;
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
vector<int> adj[401];

void go(int p) {
  int mx1 = -1, mx2 = -1;
  int y = -1, x = -1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j]) continue;

      int cnt1 = 0, cnt2 = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (!a[ny][nx])
          cnt2++;
        else if (find(adj[p].begin(), adj[p].end(), a[ny][nx]) != adj[p].end())
          cnt1++;
      }

      if (cnt1 > mx1) {
        mx1 = cnt1;
        mx2 = cnt2;
        y = i;
        x = j;
      } else if (cnt1 == mx1 && cnt2 > mx2) {
        mx2 = cnt2;
        y = i;
        x = j;
      }
    }
  }

  a[y][x] = p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> x;
    for (int j = 0; j < 4; j++) {
      int tmp;
      cin >> tmp;
      adj[x].push_back(tmp);
    }
    go(x);
  }

  s[1] = 1;
  s[2] = 10;
  s[3] = 100;
  s[4] = 1000;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (find(adj[a[i][j]].begin(), adj[a[i][j]].end(), a[ny][nx]) !=
            adj[a[i][j]].end())
          cnt++;
      }
      ans += s[cnt];
    }
  }

  cout << ans;

  return 0;
}