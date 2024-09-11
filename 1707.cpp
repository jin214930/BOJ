#include <bits/stdc++.h>
using namespace std;

int t, v, e, visited[20001];
vector<int> adj[20001];
bool flag;

void bfs(int x, int k) {
  queue<int> q;
  q.push(x);
  visited[x] = k;

  while (q.size()) {
    x = q.front();
    q.pop();

    for (int nx : adj[x]) {
      if (!visited[nx]) {
        q.push(nx);
        visited[nx] = visited[x] * -1;
      } else if (visited[nx] + visited[x]) {
        flag = false;
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> v >> e;
    memset(visited, 0, sizeof(visited));
    flag = true;
    for (int i = 1; i <= v; i++) adj[i].clear();

    while (e--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) {
      if (!flag) break;
      if (!visited[i]) bfs(i, 1);
    }

    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}