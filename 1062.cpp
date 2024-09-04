#include <bits/stdc++.h>
using namespace std;

int n, k, alpha[26], ans;
vector<string> v;

int check() {
  int cnt = 0;
  for (string s : v) {
    bool flag = true;
    for (char c : s) {
      if (!alpha[c - 'a']) {
        flag = false;
        break;
      }
    }
    if (flag) cnt++;
  }
  return cnt;
}

void go(int idx, int cnt) {
  if (cnt == k) {
    ans = max(ans, check());
    return;
  }

  for (int i = idx; i < 26; i++) {
    if (!alpha[i]) {
      alpha[i] = 1;
      go(i, cnt + 1);
      alpha[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  if (k < 5) {
    cout << 0;
    return 0;
  }

  alpha['a' - 'a'] = 1;
  alpha['n' - 'a'] = 1;
  alpha['t' - 'a'] = 1;
  alpha['i' - 'a'] = 1;
  alpha['c' - 'a'] = 1;
  go(1, 5);

  cout << ans;

  return 0;
}