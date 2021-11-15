#include <bits/stdc++.h>
using namespace std;

#define MAX 1000006
#define NMOD 4

const int MOD[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 6277, (int)1e9 + 8277 };
const int BASE = 277;

char s[MAX], t[MAX];
int pw[NMOD][MAX];
int hashS[NMOD][MAX], hashT[NMOD][MAX];

void process() {
	for (int j = 0; j < NMOD; j++) {
		pw[j][0] = 1;
		for (int i = 1; i < MAX; i++) pw[j][i] = 1LL * pw[j][i-1] * BASE % MOD[j];
	}
	
	int ls = (int)strlen(s + 1);
	for (int i = 1; i <= ls; i++) for (int j = 0; j < NMOD; j++) 
		hashS[j][i] = (hashS[j][i-1] + 1LL * s[i] * pw[j][i]) % MOD[j];

	int lt = (int)strlen(t + 1);
	for (int i = 1; i <= lt; i++) for (int j = 0; j < NMOD; j++)
		hashT[j][i] = (hashT[j][i-1] + 1LL * t[i] * pw[j][i]) % MOD[j];
}

bool check(int l, int r, int u, int v) {
	if (r - l != v - u) return false;

	for (int j = 0; j < NMOD; j++) {
		int a = (hashS[j][r] - hashS[j][l-1] + MOD[j]) % MOD[j];
		a = (1LL * a * pw[j][u]) % MOD[j];

		int b = (hashT[j][v] - hashT[j][u-1] + MOD[j]) % MOD[j];
		b = (1LL * b * pw[j][l]) % MOD[j];

		if (a != b) return false;
	}
	return true;
}

int main() {
	cin >> (s + 1); s[0] = ' ';
	cin >> (t + 1); t[0] = ' ';

	process();

	int ls = (int)strlen(s+1);
	int lt = (int)strlen(t+1);

	for (int i = 1; i <= ls - lt + 1; i++) {
		if (check(i, i+lt-1, 1, lt)) cout << i << ' ';
	}

	return 0;
}