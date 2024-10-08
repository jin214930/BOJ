#include <bits/stdc++.h>
using namespace std;

int n;
char a[10][10];
vector<int> v;

bool check(int idx) {
  int sum = 0;
  for (int i = idx; i >= 0; i--) {
    sum += v[i];
    if (a[i][idx] == '+' && sum <= 0) return false;
    if (a[i][idx] == '-' && sum >= 0) return false;
    if (a[i][idx] == '0' && sum != 0) return false;
  }
  return true;
}

void go(int idx) {
  if (idx == n) {
    for (int i : v) cout << i << ' ';
    exit(0);
  }

  for (int i = -10; i <= 10; i++) {
    v.push_back(i);
    if (check(idx)) go(idx + 1);
    v.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) cin >> a[i][j];
  }

  go(0);

  return 0;
}