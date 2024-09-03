#include <bits/stdc++.h>
using namespace std;

int n, k, visited[2][500001], cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  queue<int> q;
  q.push(n);
  visited[0][n] = 1;

  while (true) {
    queue<int> tmp;
    k += cnt;
    if (k > 500000) {
      cout << -1;
      return 0;
    }
    if (visited[cnt % 2][k]) {
      cout << cnt;
      return 0;
    }
    cnt++;
    while (q.size()) {
      int x = q.front();
      q.pop();
      for (int nx : {x + 1, x - 1, 2 * x}) {
        if (nx >= 0 && nx <= 500000 && !visited[cnt % 2][nx]) {
          tmp.push(nx);
          visited[cnt % 2][nx] = 1;
        }
      }
    }
    q = tmp;
  }

  return 0;
}