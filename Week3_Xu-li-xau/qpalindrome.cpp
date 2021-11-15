#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4 + 4;

int dp[MAX_N];
vector<int> idBegin[MAX_N];
string s;
int n;

void solve(char c) {
	s = s + c;
	n++;

	dp[n] = dp[n-1];
	idBegin[n] = {};
	for (int i: idBegin[n-1]) {
		if (s[i-1] == c) {
			idBegin[n].push_back(i-1);
			dp[n]++;
		}
	}

	if (s[n-1] == s[n]) {
		idBegin[n].push_back(n-1);
		dp[n]++;
	}
	idBegin[n].push_back(n);
	dp[n]++;
}

void test() {
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	cout << v.size() << '\n';
	v = {};
	cout << v.size() << '\n';
}

int main() {
	// test(); return 0;

	int q; cin >> q;
	n = 0;
	s = " ";

	while (q--) {
		char c; cin >> c;
		if (c == '-') {
			n--;
			s.pop_back();
		}
		else {
			solve(c);
		}
		cout << dp[n] << ' ';
	}

	return 0;
}