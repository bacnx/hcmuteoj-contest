#include <bits/stdc++.h>
using namespace std;

#define MASK(n) (1LL << (n))
#define BIT(n, i) (((n) >> i) & 1)
#define ll long long
const int MAX = 1e9;

struct Rect {
	int u, v, x, y;
	Rect(int _u = -MAX, int _v = -MAX, int _x = MAX, int _y = MAX) {
		u = _u; v = _v; x = _x; y = _y;
	}

	ll area() {
		if (x < u || y < v) return 0;
		return 1LL * (x - u) * (y - v);
	}
};

Rect merge(Rect a, Rect b) {
	Rect ans;
	ans.u = max(a.u, b.u);
	ans.v = max(a.v, b.v);
	ans.x = min(a.x, b.x);
	ans.y = min(a.y, b.y);
	return ans;
}


int n;
Rect a[22];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].u >> a[i].y >> a[i].x >> a[i].v;
	}


	ll ans = 0;
	int n_mask = MASK(n);

	for (int mask = 1; mask < n_mask; mask++) {
		int cnt_mask = 0;
		Rect rect;

		for (int i = 0; i < n; i++) if (BIT(mask, i)) {
			cnt_mask++;
			rect = merge(rect, a[i]);
		} 

		if (cnt_mask % 2 == 1)
			ans += rect.area();
		else 
			ans -= rect.area();
	}

	cout << ans;

	return 0;
}