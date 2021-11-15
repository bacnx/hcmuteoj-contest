#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 202;
const int INF = 1e9 + 9;

int m, n, a[MAX_N][MAX_N];
int dp[2*MAX_N][MAX_N][MAX_N][MAX_N][MAX_N];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		cin >> a[i][j];
	}



	return 0;
}