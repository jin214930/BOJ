#include <bits/stdc++.h>
using namespace std;

int n, flag;
long long a[100];
map<long long, int> mp;

void go(vector<long long> v) {
  if (flag) return;
  if (v.size() == n) {
    for (int i = 0; i < n; i++) cout << v[i] << ' ';
    flag = 1;
    return;
  }

  long long tmp = v[v.size() - 1];
  if (tmp % 3 == 0 && mp[tmp / 3]) {
    mp[tmp / 3] = 0;
    v.push_back(tmp / 3);
    go(v);
    mp[tmp / 3] = 1;
    v.pop_back();
  }

  if (mp[tmp * 2]) {
    mp[tmp * 2] = 0;
    v.push_back(tmp * 2);
    go(v);
    mp[tmp * 2] = 1;
    v.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = 1;
  }

  vector<long long> v;
  for (int i = 0; i < n; i++) {
    mp[a[i]] = 0;
    v.push_back(a[i]);
    go(v);
    mp[a[i]] = 1;
    v.pop_back();
  }

  return 0;
}