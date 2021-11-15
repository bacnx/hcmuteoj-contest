#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 252;

#define ll long long
typedef pair<int, int> pii;
#define fi first
#define se second

#define MASK(i) (1LL << (i))
#define BIT(n, i) (((n) >> (i)) & 1LL)

struct Rect {
	int x, y, u, v;

	Rect(int _x, int _y, int _u, int _v) {
		x = _x; y = _y;
		u = _u; v = _v;
	}

	void format(int _x, int _y, int _u, int _v) {
		x = max(x, _x); x = min(x, _u);
		y = max(y, _y); y = min(y, _v);
		u = max(u, _x); u = min(u, _u);
		v = max(v, _y); v = min(v, _v);

		if (x > u || y > v) {
			x = y = u = v = 0;
		}
	}

	Rect together(Rect r) {
		return Rect(max(x, r.x), max(y, r.y), // điểm trên trái
					min(u, r.u), min(v, r.v)); // điểm dưới phải
	}
};

int n, k, r, p, a[MAX_N][MAX_N];
ll prefix[MAX_N][MAX_N];

ll getPrefix(Rect sq) {
	sq.format(1, 1, n, n);
	int u = sq.x, v = sq.y; // điểm trên trái
	int x = sq.u, y = sq.v; // dưới phải

	return prefix[x][y]
		- prefix[u-1][y] - prefix[x][v-1]
		+ prefix[u-1][v-1];
}

ll getArea(vector<Rect> rects) {
	ll ans = 0;
	int n_mask = MASK(p);

	for (int mask = 1; mask < n_mask; mask++) {
		int count_bit = 0;
		Rect together(1, 1, n, n);
		
		for (int i = 0; i < p; i++) if (BIT(mask, i)) {
			count_bit++;
			together = together.together(rects[i]);
		}

		if (!count_bit) continue;

		// số lượng hình là chẵn thì trừ
		if (count_bit % 2 == 0) { 
			ans -= getPrefix(together);
		}
		// số lượng hình là lẻ thì cộng
		else { 
			ans += getPrefix(together);
		}
	}
	return ans;
}

/*
- Viết 1 struct hình chữ nhật rect
- Hàm tìm phần giao nhau của 2 HCN: 
	input(2 hình chữ nhật)
	output(1 hình chữ nhật là giao của 2 HCN)
- Hàm tìm tổng bao phủ của p HCN:
	input: vector p HCN
	output: tổng phần bao phủ

*/

int main() {
	cin >> n >> k >> r >> p;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		cin >> a[i][j];
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		prefix[i][j] = 1LL * a[i][j] - prefix[i-1][j-1]
					+ prefix[i-1][j] + prefix[i][j-1];
	}

	ll ans = 0;
	while (k--) {
		vector<Rect> rects;
		for (int i = 0; i < p; i++) {
			int x, y; cin >> x >> y;

			Rect sq(x, y, x + r - 1, y + r - 1);
			sq.format(1, 1, n, n);
			rects.push_back(sq);
		}

		ans = max(ans, getArea(rects));
	}
	cout << ans;

	return 0;
}