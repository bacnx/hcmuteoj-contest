#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n) {
	int ans = m/3 * n;
	ans += (n/3) * (m%3);

	if (m % 3 != 0 && n % 3 != 0) {
		if ((m % 3) * (n % 3) == 4) ans += 2;
		else ans ++;
	}

	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		cout << solve(m, n) << '\n';
	}

	return 0;
}