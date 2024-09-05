#include <bits/stdc++.h>
using namespace std;

int n, alpha[26], ans;
vector<string> v;
map<char, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) alpha[c - 'A'] = 1;
    v.push_back(s);
  }

  vector<char> a;
  for (int i = 0; i < 26; i++) {
    if (alpha[i]) a.push_back(i + 'A');
  }

  sort(a.begin(), a.end());
  do {
    for (int i = 0; i < a.size(); i++) mp[a[i]] = 9 - i;
    int sum = 0;
    for (string s : v) {
      int tmp = 0;
      for (char c : s) {
        tmp *= 10;
        tmp += mp[c];
      }
      sum += tmp;
    }
    ans = max(ans, sum);
  } while (next_permutation(a.begin(), a.end()));

  cout << ans;

  return 0;
}