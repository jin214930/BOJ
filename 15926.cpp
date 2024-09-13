#include <bits/stdc++.h>
using namespace std;

int n, a[200000], ans, cnt;
string s;
stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s;
  for(int i = 0; i < n;i++) {
    if(s[i] == '(') st.push(i);
    else if(s[i] == ')' && st.size()) {
      a[i] = 1;
      a[st.top()] = 1;
      st.pop();
    }
  }

  for(int i = 0; i < n;i++) {
    if(a[i]) 
    cnt++;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);

  cout << ans;

  return 0;
}