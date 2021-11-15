#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime(int a) {
	if (a < 2) return false;
	int n = sqrt(a);
	for (int i = 2; i <= n; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

bool isBprime(ll a) {
	int sqrt_a = sqrt(a);
	if (1LL * sqrt_a * sqrt_a != a) {
		return false;
	}
	return isPrime(sqrt_a);
}

int main() {
	int n; cin >> n;
	while (n--) {
		ll a; cin >> a;
		if (isBprime(a)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}