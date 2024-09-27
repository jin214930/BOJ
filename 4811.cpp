#include <bits/stdc++.h>
using namespace std;

long long n, d[31][31];

long long go(int a, int b) {
  if (a == 0 && b == 0) return 1;
  long long& ret = d[a][b];
  if (ret) return ret;
  if (a > 0) ret += go(a - 1, b + 1);
  if (b > 0) ret += go(a, b - 1);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> n;
    if (!n) break;
    cout << go(n, 0) << '\n';
  }

  return 0;
}