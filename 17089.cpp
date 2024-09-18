#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[4001], ans = 999999999;
int adj[4001][4001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
    cnt[a]++;
    cnt[b]++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (adj[i][j]) {
        for (int k = 1; k <= n; k++) {
          if (adj[k][i] && adj[k][j]) {
            int sum = cnt[i] + cnt[j] + cnt[k] - 6;
            ans = min(ans, sum);
          }
        }
      }
    }
  }

  if (ans == 999999999)
    cout << -1;
  else
    cout << ans;

  return 0;
}