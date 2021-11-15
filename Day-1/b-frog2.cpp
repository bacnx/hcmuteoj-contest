#include <bits/stdc++.h>
using namespace std;

int n, k, h[100005];
int dp[100005];

void jump(int i, int j) {
	dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1000000009;
	}

	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k && i + j <= n; j++) {
			jump(i, i + j);
		}
	}

	cout << dp[n];

	return 0;
}