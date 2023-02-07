#include <bits/stdc++.h> 
using namespace std;

int n;
char a, b, c;
string pre, in, post;
char adj[26][2];

void preorder(char x) {
	if (x == '.')
		return;
	pre += x;
	preorder(adj[x - 'A'][0]);
	preorder(adj[x - 'A'][1]);
}

void inorder(char x) {
	if (x == '.')
		return;
	inorder(adj[x - 'A'][0]);
	in += x;
	inorder(adj[x - 'A'][1]);
}

void postorder(char x) {
	if (x == '.')
		return;
	postorder(adj[x - 'A'][0]);
	postorder(adj[x - 'A'][1]);
	post += x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		adj[a - 'A'][0] = b;
		adj[a - 'A'][1] = c;
	}

	preorder('A');
	inorder('A');
	postorder('A');

	cout << pre << '\n' << in << '\n' << post;

	return 0;
}