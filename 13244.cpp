#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, visited[1001], x;
vector<int> adj[1001];

int dfs(int x) {
  int cnt = 1;
  visited[x] = 1;

  for(int nx : adj[x]) {
    if(!visited[nx]) 
      cnt += dfs(nx);
  }

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n >> m;
    for(int i = 1; i <= 1000;i++)
    adj[i].clear();
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
      x = a;
    }

    if(m != n-1) {
      cout << "graph\n";
      continue;
    }

    if(dfs(x) == n) {
      cout << "tree\n";
    }else
      cout << "graph\n";
  }

  return 0;
}