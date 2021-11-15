#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 3;
const int MOD = 1e9 + 7;

int m, n;
char a[MAX_N][MAX_N];
int paths[MAX_N][MAX_N];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		cin >> a[i][j];
	}
	a[1][1] = 'b';

	paths[1][1] = 1;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) if (a[i][j] == '.') {
		paths[i][j] = (paths[i-1][j] + paths[i][j-1]) % MOD;
	}
	cout << paths[m][n];

	return 0;
}