#include <bits/stdc++.h>
using namespace std;

int n, a[80002], b[80002];
long long ans;
stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = 1000000000;

  for (int i = 1; i <= n + 1; i++) {
    while (st.size() && a[st.top()] <= a[i]) {
      b[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  for (int i = 1; i <= n; i++) ans += b[i] - i - 1;
  cout << ans;

  return 0;
}