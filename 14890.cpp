#include <bits/stdc++.h>
using namespace std;

int n, l, a[100][100], b[100][100], ans;

void go(int a[][100]) {
  for (int i = 0; i < n; i++) {
    int visited[100] = {0};
    bool flag = true;
    for (int j = 0; j < n - 1; j++) {
      if (a[i][j] - 1 == a[i][j + 1]) {
        int tmp = a[i][j + 1];
        for (int k = j + 1; k < j + 1 + l; k++) {
          if (k >= n || a[i][k] != tmp) {
            flag = false;
            break;
          }
        }
        if (flag)
          visited[j + l] = 1;
        else
          break;
      } else if (a[i][j] + 1 == a[i][j + 1]) {
        int tmp = a[i][j];
        for (int k = j; k > j - l; k--) {
          if (k < 0 || a[i][k] != tmp || visited[k]) {
            flag = false;
            break;
          }
        }
        if (!flag) break;
      } else if (a[i][j] != a[i][j + 1]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      b[j][i] = a[i][j];
    }
  }

  go(a);
  go(b);

  cout << ans;

  return 0;
}