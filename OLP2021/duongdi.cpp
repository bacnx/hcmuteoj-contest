#include <bits/stdc++.h>
using namespace std;

int n, a[102][102];
int dp[102][102][102];

void getIdUp(int d, int u, int &x, int &y) {
	x = u;
	y = d - u + 1;
}
void getIdDown(int d, int v, int &x, int &y) {
	x = n - (d - v + 1) + 1;
	y = n - v + 1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> a[i][j];

	if (a[1][1] == a[n][n]) dp[1][1][1] = 1;
	for (int d = 2; d <= n; d++) for (int u = 1; u <= d; u++) for (int v = 1; v <= d; v++) {
		int x1, y1, x2, y2; 
		getIdUp(d, u, x1, y1);
		getIdDown(d, v, x2, y2);

		if (a[x1][y1] == a[x2][y2]) {
			dp[d][u][v] += dp[d-1][u-1][v-1];
			dp[d][u][v] += dp[d-1][u-1][v];
			dp[d][u][v] += dp[d-1][u][v-1];
			dp[d][u][v] += dp[d-1][u][v];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[n][i][i];
	}
	cout << ans;

	return 0;
}