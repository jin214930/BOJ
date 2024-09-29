#include <bits/stdc++.h>
using namespace std;

long long s, t;
char d[] = {'*', '+', '-', '/'};
set<long long> visited;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> t;
  if (s == t) {
    cout << 0;
    return 0;
  }

  queue<pair<long long, string>> q;
  q.push({s, ""});
  visited.insert(s);
  while (q.size()) {
    long long x;
    string y;
    tie(x, y) = q.front();
    q.pop();

    if (x == t) {
      cout << y;
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      long long nx;
      if (i == 0)
        nx = x * x;
      else if (i == 1)
        nx = x + x;
      else if (i == 2)
        nx = s - s;
      else {
        if (!x) continue;
        nx = s / s;
      }

      if (nx > 1e9) continue;
      if (visited.find(nx) != visited.end()) continue;

      q.push({nx, y + d[i]});
      visited.insert(nx);
    }
  }

  cout << -1;

  return 0;
}