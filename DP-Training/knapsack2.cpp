#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e2+2;
const int MAX_V = 1e5+5;

#define ll long long
typedef pair<int, int> pii;
#define fi first
#define se second

int n, w, v;
pii items[MAX_N];
ll dp[MAX_N][MAX_V];

int main() {
	cin >> n >> w;
	v = 0;
	for (int i = 1; i <= n; i++) {
		cin >> items[i].fi >> items[i].se;
		v += items[i].se;
	}

	/* init dp */ {
		for (int i = 0; i <= n; i++) for (int j = 1; j <= v; j++) {
			dp[i][j] = 1e13;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= v; j++) {
		dp[i][j] = dp[i-1][j];
		if (j >= items[i].se) {
			dp[i][j] = min(dp[i][j], dp[i-1][j-items[i].se] + items[i].fi);
		}
		if (dp[i][j] <= w) {
			ans = max(ans, j);
		}
		// cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
	}
	cout << ans;


	return 0;
}