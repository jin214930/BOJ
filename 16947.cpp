#include <bits/stdc++.h>
using namespace std;

int n, sx, cycle[3001], visited[3001];
bool flag;
vector<int> adj[3001];

int bfs(int x) {
  if (cycle[x]) return 0;
  queue<int> q;
  visited[x] = 1;
  q.push(x);

  while (q.size()) {
    x = q.front();
    q.pop();
    for (int nx : adj[x]) {
      if (!visited[nx]) {
        if (cycle[nx])
          return visited[x];
        else {
          q.push(nx);
          visited[nx] = visited[x] + 1;
        }
      }
    }
  }
}

void dfs(int x, int px) {
  cycle[x] = 1;

  for (int nx : adj[x]) {
    if (cycle[nx] && nx != px && nx == sx) {
      flag = true;
      return;
    }
    if (!cycle[nx]) dfs(nx, x);
    if (flag) return;
  }
  cycle[x] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    memset(cycle, 0, sizeof(cycle));
    sx = i;
    dfs(i, -1);
    if (flag) break;
  }

  for (int i = 1; i <= n; i++) {
    memset(visited, 0, sizeof(visited));
    cout << bfs(i) << ' ';
  }

  return 0;
}