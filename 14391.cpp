#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char a[4][4];
vector<int> v;

void go() {
  if (v.size() == n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int tmp = 0;
      for (int j = 0; j < m; j++) {
        if (v[i] & (1 << j))
          tmp = tmp * 10 + a[i][j] - '0';
        else {
          sum += tmp;
          tmp = 0;
        }
      }
      if (tmp) sum += tmp;
    }

    for (int i = 0; i < m; i++) {
      int tmp = 0;
      for (int j = 0; j < n; j++) {
        if (v[j] & (1 << i)) {
          sum += tmp;
          tmp = 0;
        } else
          tmp = tmp * 10 + a[j][i] - '0';
      }
      if (tmp) sum += tmp;
    }

    ans = max(ans, sum);
    return;
  }

  for (int i = 0; i < (1 << m); i++) {
    v.push_back(i);
    go();
    v.pop_back();
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

  go();

  cout << ans;

  return 0;
}