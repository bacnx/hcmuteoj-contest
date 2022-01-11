#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define ll long long

int n;
int a[200005], b[200005];
pii p[200005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		p[i] = pii(a[i], b[i]);
	}

	a[n+1] = b[n+1] = 1000000009;
	n++;

	ll ans = 0, cnt;

	cnt = 1;
	sort(a + 1, a + n);
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i-1]) {
			cnt++;
		} 
		else {
			ans += cnt*(cnt-1)/2;
			cnt = 1;
		}
	}

	cnt = 1;
	sort(b + 1, b + n);
	for (int i = 2; i <= n; i++) {
		if (b[i] == b[i-1]) {
			cnt++;
		} 
		else {
			ans += cnt*(cnt-1)/2;
			cnt = 1;
		}
	}

	cnt = 1;
	sort(p + 1, p + n);
	for (int i = 2; i <= n; i++) {
		if (p[i] == p[i-1]) {
			cnt++;
		} 
		else {
			ans -= cnt*(cnt-1)/2;
			cnt = 1;
		}
	}

	cout << ans;

	return 0;
}