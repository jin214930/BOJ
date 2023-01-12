#include <bits/stdc++.h>
using namespace std;

string s;

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> s;
		if (s == "end")
			break;
		int cnt1 = 0, cnt2 = 0;
		bool hasVowel = false;
		bool flag = false;

		for (int i = 0; i < s.size(); i++) {
			if (isVowel(s[i])) {
				cnt1++;
				cnt2 = 0;
				hasVowel = true;
			}
			else {
				cnt2++;
				cnt1 = 0;
			}
			if (i >= 1 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o')
				flag = true;
			if (cnt1 == 3 || cnt2 == 3)
				flag = true;
		}

		if (!hasVowel)
			flag = true;
		if (flag)
			cout << "<" << s << "> is not acceptable.\n";
		else
			cout << "<" << s << "> is acceptable.\n";

	}

	return 0;
}