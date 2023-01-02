#include <bits/stdc++.h>
using namespace std;

int w, h, p, q, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h >> p >> q >> t;
	int dx = 1, dy = 1;
	int pt = t % (2 * w), qt = t % (2 * h);
	while (pt--) {
		if (p + dx == w + 1 || p + dx == -1)
			dx *= -1;
		p += dx;
	}
	while (qt--) {
		if (q + dy == h + 1 || q + dy == -1)
			dy *= -1;
		q += dy;
	}

	cout << p << ' ' << q;

	return 0;
}