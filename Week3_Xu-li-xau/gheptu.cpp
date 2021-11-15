#include <bits/stdc++.h>
using namespace std;

string reverse(string s) {
	int n = s.size();
	for (int i = 0; i <= n/2 - 1; i++) {
		swap(s[i], s[n-1 - i]);
	}
	return s;
}

int main() {
	string s, a, b;
	bool isReverse = false;
	cin >> s;

	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			isReverse ^= 1;
			continue;
		}

		int f; cin >> f;
		char c; cin >> c;
		if (isReverse) {
			if (f == 1) f++;
			else f--;
		}

		if (f == 1) {
			a.push_back(c);
		} else {
			b.push_back(c);
		}
	}

	s = reverse(a) + s + b;
	if (isReverse) s = reverse(s);

	cout << s;

	return 0;
}