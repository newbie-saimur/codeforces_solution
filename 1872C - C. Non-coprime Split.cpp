#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

int minDivisor(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return i;
	}
	return n;
}

void solve() {
	int a, b; cin >> a >> b;

	for (int i = a; i <= b; i++) {
		int min_div = minDivisor(i);
		if (min_div != i) {
			cout << min_div << ' ' << i - min_div << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test = 1;
	cin >> test;
	for (_ = 1; _ <= test; _++)
	{
		solve();
	}
	return 0;
}
