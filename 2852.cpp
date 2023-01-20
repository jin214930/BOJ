#include <bits/stdc++.h>
using namespace std;

int n, tn, a, b, ta, tb;
string t, p;

int cal(string s) {
	return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

string itos(int n) {
	string m = "00" + to_string(n / 60);
	string s = "00" + to_string(n % 60);
	return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tn >> t;
		if (a > b) {
			ta += cal(t) - cal(p);
		}
		else if (b > a) {
			tb += cal(t) - cal(p);
		}
		if (tn == 1)
			a++;
		else
			b++;
		p = t;
	}

	if (a > b)
		ta += cal("48:00") - cal(p);
	else if (b > a)
		tb += cal("48:00") - cal(p);

	cout << itos(ta) << '\n';
	cout << itos(tb) << '\n';

	return 0;
}