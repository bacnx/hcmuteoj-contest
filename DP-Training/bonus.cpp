#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1003

int n, k, a[MAX_N][MAX_N];
int prefix[MAX_N][MAX_N];

int getPrefix(int u, int v, int x, int y) {
	u = max(u, 1);
	v = max(v, 1);

	return prefix[x][y]
		- prefix[x][v-1] - prefix[u-1][y]
		+ prefix[u-1][v-1];
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		cin >> a[i][j];
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		prefix[i][j] = a[i][j] - prefix[i-1][j-1]
					+ prefix[i-1][j] + prefix[i][j-1];
	}

	int ans = 0;
	for (int i = k; i <= n; i++) for (int j = k; j <= n; j++) {
		ans = max(ans, getPrefix(i-k+1, j-k+1, i, j));
	}
	cout << ans;

	return 0;
}