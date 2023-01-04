#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26], tmp;
deque<char> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (char c : s)
		cnt[c - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			dq.push_back(i + 'A');
			cnt[i]--;
			tmp++;
		}

		if (tmp > 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}

	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < cnt[i] / 2; j++) {
			dq.push_back(i + 'A');
			dq.push_front(i + 'A');
		}
	}

	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}

	return 0;
}