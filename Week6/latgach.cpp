#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;

	int ans = (n / k) * (m / k);
	if (n % k) ans += m / k;
	if (m % k) ans += n / k;
	if (n % k && m % k) ans++;

	cout << ans;

	return 0;
}