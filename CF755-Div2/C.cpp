#include <bits/stdc++.h>
using namespace std;

int n, a[102], b[102];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	bool ans = true;
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[i] || a[i] + 1 < b[i]) {
			ans = false;
			break;
		}
	}

	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}