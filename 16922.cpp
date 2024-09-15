#include <bits/stdc++.h>
using namespace std;

int n, visited[1001], ans, a[] = {1, 5, 10, 50};

void go(int cnt, int idx, int sum) {
  if (cnt == n) {
    if (!visited[sum]) {
      visited[sum] = 1;
      ans++;
    }
    return;
  }

  for (int i = idx; i < 4; i++) go(cnt + 1, i, sum + a[i]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  go(0, 0, 0);

  cout << ans;

  return 0;
}