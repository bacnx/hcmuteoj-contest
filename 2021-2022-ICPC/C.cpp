#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; int k;
	cin >> s >> k;

	int n = s.size();
	int s_min = 2 * 'z';
	char c1, c2;

	for (int i = 1; i < n; i++) {
		int tmp = s[i] + s[i-1];

		if (tmp < s_min) {
			s_min = tmp;
			c1 = s[i];
			c2 = s[i-1];
		}
	}

	if (c1 > c2) swap(c1, c2);
	// cout << c1 << c2;
	for (int i = 1; i <= k; i++) {
		cout << ((i&1) ? c1 : c2);	
	}

	return 0;
}