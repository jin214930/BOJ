#include <bits/stdc++.h>
using namespace std;

int n, x, y, d, g, a[101][101], ans;
int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};
vector<int> direc;

void go() {
  int s = direc.size();
  for (int i = s - 1; i >= 0; i--) {
    int tmp = (direc[i] + 1) % 4;
    y += dy[tmp];
    x += dx[tmp];
    a[y][x] = 1;
    direc.push_back(tmp);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  while (n--) {
    direc.clear();
    cin >> x >> y >> d >> g;
    a[y][x] = 1;
    y += dy[d];
    x += dx[d];
    a[y][x] = 1;
    direc.push_back(d);

    while (g--) go();
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) ans++;
    }
  }

  cout << ans;

  return 0;
}
