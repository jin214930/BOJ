#include <bits/stdc++.h>
using namespace std;

int n, m, r, a[100][100], b[100][100];

void go(int k) {
  switch (k) {
    case 1:
      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) swap(a[i][j], a[n - i - 1][j]);
      }
      break;
    case 2:
      for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n; j++) swap(a[j][i], a[j][m - 1 - i]);
      }
      break;
    case 3:
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) b[j][n - 1 - i] = a[i][j];
      }
      swap(n, m);
      for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) a[i][j] = b[i][j];
      }
      break;
    case 4:
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) b[m - j - 1][i] = a[i][j];
      }
      swap(n, m);
      for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) a[i][j] = b[i][j];
      }
      break;
    case 5:
      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) b[i][j] = a[i][j];
      }

      for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) a[i - n / 2][j] = a[i][j];
      }

      for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) a[i][j - m / 2] = a[i][j];
      }

      for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) a[i + n / 2][j] = a[i][j];
      }

      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) a[i][j + m / 2] = b[i][j];
      }
      break;

    default:
      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) b[i][j] = a[i][j];
      }

      for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) a[i][j - m / 2] = a[i][j];
      }

      for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) a[i - n / 2][j] = a[i][j];
      }

      for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) a[i][j + m / 2] = a[i][j];
      }

      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) a[i + n / 2][j] = b[i][j];
      }
      break;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  for (int i = 0; i < r; i++) {
    int tmp;
    cin >> tmp;
    go(tmp);
  }

  cout << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }

  return 0;
}