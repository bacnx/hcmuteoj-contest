#include <bits/stdc++.h>
using namespace std;

const double esp = 5e-7;

int main() {
	int n, k, d, s;
	cin >> n >> k >> d >> s;

	if (n - k == 0) {
		cout << "impossible";
		return 0;
	}

	double x = (double)(1LL * n * d - 1LL * k * s) / (n - k);
	if (x < 100 + esp) {
		cout << setprecision(7) << fixed << x;
	}
	else {
		cout << "impossible";
	}

	return 0;
}