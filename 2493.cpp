#include <bits/stdc++.h>
using namespace std;

int n, a[500001], ans[500001];
stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 1; i <= n; i++) {
    while (st.size() && a[st.top()] < a[i]) st.pop();
    if (st.size()) ans[i] = st.top();
    st.push(i);
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

  return 0;
}