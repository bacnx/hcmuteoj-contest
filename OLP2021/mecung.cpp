#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long

int pow3(int n) {
	if (n == 1) return 3;
	else if (n == 0) return 1;

	int pw = pow3(n/2);
	int ans = (1LL * pw * pw) % MOD;
	if (n % 2 == 1) ans = (1LL * ans * 3) % MOD;
	return ans;
}

int n, k;
vector<pair<int, int>> v;

int32_t main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a, b; cin >> a >> b;
		v.push_back({b, a});
	}

	sort(v.begin(), v.end());
	v.push_back({-1, -1});
	int l = 1, cnt_col = 0;
	int cnt = 1;
	for (int i = 1; i <= k; i++) if (v[i] != v[i-1]) {
		if (v[i].first == v[i-1].first) {
			cnt++;
		}
		else {
			l = (1LL * l * (3 - cnt)) % MOD;
			cnt = 1;
			cnt_col++;
		}
	}

	l = (1LL * l * pow3(n - cnt_col)) % MOD;
	cout << l;

	return 0;
}