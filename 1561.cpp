#include <bits/stdc++.h>
using namespace std;

long long n, m, a[10000], ans;

bool check(long long mid) {
  long long tmp = m;
  for (int i = 0; i < m; i++) tmp += mid / a[i];
  return tmp >= n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];

  if (n <= m) {
    cout << n;
    return 0;
  }

  long long start = 0;
  long long end = 60000000002;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (check(mid)) {
      end = mid - 1;
      ans = mid;
    } else
      start = mid + 1;
  }

  long long tmp = m;
  for (int i = 0; i < m; i++) tmp += (ans - 1) / a[i];

  for (int i = 0; i < m; i++) {
    if (ans % a[i] == 0) tmp++;
    if (tmp == n) {
      cout << i + 1;
      return 0;
    }
  }

  return 0;
}