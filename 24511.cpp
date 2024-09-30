#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[100000];
deque<int> dq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    if (!a[i]) dq.push_front(b);
  }

  cin >> m;
  while (m--) {
    cin >> c;
    dq.push_back(c);
    cout << dq.front() << ' ';
    dq.pop_front();
  }

  return 0;
}