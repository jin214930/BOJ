#include <bits/stdc++.h>
using namespace std;

string s, p, ans;
stack<char> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> p;

  for (int i = 0; i < s.size(); i++) {
    st.push(s[i]);
    if (s[i] == p[p.size() - 1] && st.size() >= p.size()) {
      string tmp = "";
      for (int j = 0; j < p.size(); j++) {
        tmp += st.top();
        st.pop();
      }
      reverse(tmp.begin(), tmp.end());
      if (tmp != p) {
        for (char c : tmp) st.push(c);
      }
    }
  }

  while (st.size()) {
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());

  if (ans == "")
    cout << "FRULA";
  else
    cout << ans;

  return 0;
}