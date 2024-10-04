#include <bits/stdc++.h>
using namespace std;

int a[10], b[4], v[33], ans;
vector<int> adj[33];

int move(int x, int cnt) {
  if (x == 100) return 100;
  if (adj[x].size() >= 2) {
    x = adj[x][1];
    cnt--;
  }
  while (cnt--) {
    if (x == 100) break;
    x = adj[x][0];
  }
  return x;
}

bool check(int x, int idx) {
  if (x == 100) return false;
  for (int i = 0; i < 4; i++) {
    if (i == idx) continue;
    if (b[i] == x) return true;
  }
  return false;
}
void add(int x, int y) { adj[x].push_back(y); }

void setMap() {
  for (int i = 0; i <= 19; i++) add(i, i + 1);
  add(5, 21), add(21, 22), add(22, 23), add(23, 24), add(15, 29), add(29, 30),
      add(30, 31), add(31, 24), add(10, 27), add(27, 28), add(28, 24),
      add(24, 25), add(25, 26), add(26, 20), add(20, 100);

  v[1] = 2, v[2] = 4, v[3] = 6, v[4] = 8, v[5] = 10, v[6] = 12, v[7] = 14,
  v[8] = 16, v[9] = 18, v[10] = 20, v[11] = 22, v[12] = 24, v[13] = 26,
  v[14] = 28, v[15] = 30, v[16] = 32, v[17] = 34, v[18] = 36, v[19] = 38,
  v[20] = 40, v[21] = 13, v[22] = 16, v[23] = 19, v[24] = 25, v[27] = 22,
  v[28] = 24, v[25] = 30, v[26] = 35, v[29] = 28, v[30] = 27, v[31] = 26;
}

void go(int idx, int sum) {
  if (idx == 10) {
    ans = max(ans, sum);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int move_idx = move(b[i], a[idx]);
    if (check(move_idx, i)) continue;
    int tmp = b[i];
    b[i] = move_idx;
    go(idx + 1, sum + v[move_idx]);
    b[i] = tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  setMap();
  for (int i = 0; i < 10; i++) cin >> a[i];
  go(0, 0);
  cout << ans;

  return 0;
}
