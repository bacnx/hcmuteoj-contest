#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

	int ans = 0;
	bool all_1 = false;
	for (int i = 0; i < s.size(); i++) {
		int a = 0;

		if (s[i] != '0' || all_1) {
			a = 1;
			if (s[i] != '1') all_1 = true;
		}

		ans = ((ans << 1) | a);
	}
	cout << ans;

	return 0;
}