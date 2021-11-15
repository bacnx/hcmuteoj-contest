#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	s = " " + s;

	for (int i = 1; i <= n; i++) {
		if ((i % 2 == 1 && 'A' <= s[i] && s[i] <= 'Z')
		 || (i % 2 == 0 && 'a' <= s[i] && s[i] <= 'z')) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

	return 0;
}