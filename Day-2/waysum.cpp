#include <bits/stdc++.h>
using namespace std;

long long sum(int n) {
	if (n < 1) return 0;
	return 1LL * n * (n + 1) / 2;
}

long long waySum(int x, int y, int z, int t) {
	if (x > z || y > t) return 0;
	int m = z - x + 1, n = t - y + 1;
	if (m > n) swap(m, n);

	return sum(m-2) * 2 + (m-1) * (n-m+1) + 1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int x, y, u, v; cin >> x >> y >> u >> v;
		cout << waySum(x, y, u, v) << "\n";
	}

	return 0;
}