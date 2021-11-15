#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

int n, w;
pii a[102];
long long dp[102][100005];

int main() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= a[i].fi) {
				dp[i][j] = max(dp[i][j], dp[i-1][j - a[i].fi] + a[i].se);
			}
		}
	}

	cout << dp[n][w];

	return 0;
}