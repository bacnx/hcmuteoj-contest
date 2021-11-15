#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e3 + 3;
typedef pair<int, int> pii;

string s, t;
int dp[MAX_N][MAX_N];
pii trace[MAX_N][MAX_N];

int main() {
	cin >> s >> t;
	s = " " + s; t = " " + t;
	int size_s = s.size() - 1, size_t = t.size() - 1;

	for (int i = 1; i <= size_s; i++) for (int j = 1; j <= size_t; j++) {
		if (dp[i-1][j] > dp[i][j-1]) {
			dp[i][j] = dp[i-1][j];
			trace[i][j] = trace[i-1][j];
		}
		else {
			dp[i][j] = dp[i][j-1];
			trace[i][j] = trace[i][j-1];
		}

		if (s[i] == t[j] && dp[i-1][j-1] + 1 > dp[i][j]) {
			dp[i][j] = dp[i-1][j-1] + 1;
			trace[i][j] = pii(i, j);
		}
	}

	string ans = "";
	/* trace */ {
		int u = size_s, v = size_t;
		while (u != 0 && v != 0) {
			int x = trace[u][v].first;
			int y = trace[u][v].second;

			if (u == x && v == y) {
				ans = s[u] + ans;
				u--, v--;
			}
			else {
				u = x;
				v = y;
			}
		}
	}
	cout << ans;

	return 0;
}