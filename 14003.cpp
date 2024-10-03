#include <bits/stdc++.h>
using namespace std;

int n, lis[1000000], len, x;
pair<int, int> ans[1000000];
stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  fill(lis, lis + 1000000, 1000000001);
  for (int i = 0; i < n; i++) {
    cin >> x;
    auto lowerPos = lower_bound(lis, lis + len, x);
    int p = lower_bound(lis, lis + len, x) - lis;
    if (*lowerPos == 1000000001) len++;
    *lowerPos = x;
    ans[i].first = p;
    ans[i].second = x;
  }

  cout << len << '\n';
  for (int i = n - 1; i >= 0; i--) {
    if (ans[i].first == len - 1) {
      st.push(ans[i].second);
      len--;
    }
  }

  while (st.size()) {
    cout << st.top() << ' ';
    st.pop();
  }

  return 0;
}