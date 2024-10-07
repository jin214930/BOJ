#include <bits/stdc++.h>
using namespace std;

int x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x;

  int tmp = 0;
  int idx = 1;
  int a, b;
  for (int i = 2; i <= 10000000; i++) {
    if (i % 2)
      b = i - 1, a = 1;
    else
      a = i - 1, b = 1;
    for (int j = 0; j < idx; j++) {
      tmp++;
      if (tmp == x) {
        cout << a << '/' << b;
        return 0;
      }
      if (i % 2)
        b--, a++;
      else
        a--, b++;
    }
    idx++;
  }

  return 0;
}