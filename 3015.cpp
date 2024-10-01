#include <bits/stdc++.h>
using namespace std;

long long n, ans;
stack<pair<long long, long long>> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    int cnt = 1;
    while (st.size() && st.top().first <= tmp) {
      ans += st.top().second;
      if (st.top().first == tmp)
        cnt = st.top().second + 1;
      else
        cnt = 1;
      st.pop();
    }
    if (st.size()) ans++;
    st.push({tmp, cnt});
  }

  cout << ans;

  return 0;
}