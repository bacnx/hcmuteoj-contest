#include <bits/stdc++.h>
using namespace std;

int main() {
	const int ans[] = {2, 3, 1, -2, -3, -1};
	long long n; cin >> n;
	cout << ans[n%6];

	return 0;
}