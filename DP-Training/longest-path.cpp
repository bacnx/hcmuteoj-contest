#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int n, m;
vector<int> adj[MAX_N];
int deep[MAX_N];

void initDeep() {
	for (int i = 1; i <= n; i++) {
		deep[i] = -1;
	}
}

int calDeep(int u) {
	if (deep[u] != -1) return deep[u];
	deep[u] = 0;

	for (int v: adj[u]) {
		deep[u] = max(deep[u], calDeep(v) + 1);
	}
	return deep[u];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	initDeep();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, calDeep(i));
	}
	cout << ans;

	return 0;
}