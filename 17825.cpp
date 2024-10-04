#include <bits/stdc++.h>
using namespace std;

int a[10], s[33], b[4], ans;
vector<int> adj[33];

int move(int x, int cnt) {
  if (adj[x].size() == 2) {
    x = adj[x][1];
    cnt--;
  }

  while (cnt--) {
    if (x == 32) break;
    x = adj[x][0];
  }

  return x;
}

bool check(int x) {
  if (x == 32) return false;
  for (int i = 0; i < 4; i++) {
    if (b[i] == x) return true;
  }
  return false;
}

void go(int idx, int sum) {
  if (idx == 10) {
    ans = max(ans, sum);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (b[i] == 32) continue;
    int move_idx = move(b[i], a[idx]);
    if (check(move_idx)) continue;
    int tmp = b[i];
    b[i] = move_idx;
    go(idx + 1, sum + s[b[i]]);
    b[i] = tmp;
  }
}

void add(int x, int y) { adj[x].push_back(y); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 10; i++) cin >> a[i];

  for (int i = 0; i < 20; i++) adj[i].push_back(i + 1);
  adj[5].push_back(21), adj[21].push_back(22), adj[22].push_back(23),
      adj[23].push_back(24), adj[24].push_back(30), adj[30].push_back(31),
      adj[31].push_back(20), adj[20].push_back(32), adj[10].push_back(25),
      adj[25].push_back(26), adj[26].push_back(24), adj[15].push_back(27),
      adj[27].push_back(28), adj[28].push_back(29), adj[29].push_back(24);

  for (int i = 1; i <= 20; i++) s[i] = i * 2;
  s[21] = 13, s[22] = 16, s[23] = 19, s[24] = 25, s[25] = 22, s[26] = 24,
  s[27] = 28, s[28] = 27, s[29] = 26, s[30] = 30, s[31] = 35;

  go(0, 0);
  cout << ans;

  return 0;
}