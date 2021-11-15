#include <bits/stdc++.h>
using namespace std;

int n, a[100005][3];
int dp[100005][3];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) if (k != j) {
				dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
			}
		}
	}

	int res = max(dp[n][0], max(dp[n][1], dp[n][2]));
	cout << res;

	return 0;
}