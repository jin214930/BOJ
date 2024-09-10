#include <bits/stdc++.h>
using namespace std;

int n, m, a[100000], ans;

bool check(int k) {
  int cnt = 1;
  int tmp = k;
  for (int i = 0; i < n; i++) {
    if (tmp - a[i] < 0) {
      tmp = k;
      cnt++;
    }
    tmp -= a[i];
  }
  return cnt <= m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];

  int start = *max_element(a, a + n);
  int end = 1000000000;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (check(mid)) {
      ans = mid;
      end = mid - 1;
    } else
      start = mid + 1;
  }

  cout << ans;

  return 0;
}