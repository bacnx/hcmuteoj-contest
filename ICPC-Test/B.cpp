#include <iostream>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

int n;
pii a[1003];

int dist(pii a, pii b) {
	return abs(b.fi - a.fi) + abs(b.se - a.se);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}

	int min_dist = 1e9;
	pii min_house = pii(1e6, 1e6);

	for (int i = 1; i <= n; i++) {
		int s = 0;
		for (int j = 1; j <= n; j++) {
			s += dist(a[i], a[j]);
		}

		if (s < min_dist) {
			min_dist = s;
			min_house = a[i];
		}
		if (s == min_dist && a[i] < min_house) 
			min_house = a[i];
	}

	cout << min_house.fi << ' ' << min_house.se;

	return 0;
}