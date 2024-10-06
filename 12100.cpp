#include <bits/stdc++.h>
using namespace std;

int n, ans, a[20][20];

void rot(int a[20][20]) {
  int tmp[20][20];
  memset(tmp, 0, sizeof(tmp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) tmp[i][j] = a[n - 1 - j][i];
  }
  memcpy(a, tmp, sizeof(tmp));
}

void move(int a[20][20]) {
  int tmp[20][20];
  memset(tmp, 0, sizeof(tmp));

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (!a[i][j]) continue;
      if (!tmp[i][cnt])
        tmp[i][cnt] = a[i][j];
      else if (tmp[i][cnt] == a[i][j]) {
        tmp[i][cnt] *= 2;
        cnt++;
      } else {
        cnt++;
        tmp[i][cnt] = a[i][j];
      }
    }
  }

  memcpy(a, tmp, sizeof(tmp));
}

void go(int idx, int a[20][20]) {
  if (idx == 5) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) ans = max(ans, a[i][j]);
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int tmp[20][20];
    memcpy(tmp, a, sizeof(tmp));
    move(tmp);
    go(idx + 1, tmp);
    rot(a);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }

  go(0, a);

  cout << ans;

  return 0;
}
