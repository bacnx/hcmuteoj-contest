#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	int n; cin >> n;
	map<ll, int> mp;

	ll ans = 0;
	mp[0]++;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (i % 2 == 0) a = -a;

		sum += a;
		ans += mp[sum];
		mp[sum]++;
	}

	cout << ans << '\n';
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}