#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
int cntAdj[100005];
int anode[100005], nAnode = 0;
bool isDisable[100005];

int main() {
	cin >> n;
	for (int u = 1; u <= n; u++) {
		int v; cin >> v;
		if (v == -1) continue;

		adj[u].push_back(v);
		adj[v].push_back(u);
		cntAdj[u]++;
		cntAdj[v]++;
	}

	for (int i = 1; i <= n; i++) if ((int)adj[i].size() == 1) {
		anode[++nAnode] = i;
	}

	int ans = 0;
	while (nAnode) {
		int node = anode[nAnode--];
		if (isDisable[node]) continue;
		int u;
		for (int i: adj[node]) if (!isDisable[i]) {
			u = i; break;
		}

		ans++;
		isDisable[u] = true; cntAdj[u]--;
		for (int v: adj[u]) if (!isDisable[v]) {
			isDisable[v] = true; cntAdj[v]--;

			for (int i: adj[v]) if(!isDisable[i]) {
				cntAdj[i]--;
				if (cntAdj[i] == 1) anode[++nAnode] = i;
			}
		}
	}

	cout << ans;

	return 0;
}