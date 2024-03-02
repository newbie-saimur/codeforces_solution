#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

int range_natural_sum(int l, int r) {
	return (l + r) * (r - l + 1) / 2;
}

void solve() {
	int n, x, y; cin >> n >> x >> y;
	int c = n / lcm(x, y);
	int a = n / x - c;
	int b = n / y - c;
	a = range_natural_sum(n - a + 1, n);
	b = range_natural_sum(1, b);
	cout << a - b << '\n';
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
