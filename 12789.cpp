#include <bits/stdc++.h>
using namespace std;

int n, k = 1;
stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == k)
      k++;
    else {
      while (st.size() && st.top() == k) {
        st.pop();
        k++;
      }
      if (x != k)
        st.push(x);
      else
        k++;
    }
  }

  while (st.size() && st.top() == k) {
    st.pop();
    k++;
  }

  cout << (k == n + 1 ? "Nice" : "Sad");

  return 0;
}