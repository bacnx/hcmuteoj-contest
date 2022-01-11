#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);

	int l = n / 2;
	int r = l + 1;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			cout << a[r++] << ' ';
		} else {
			cout << a[l--] << ' ';
		}
	}

	return 0;
}