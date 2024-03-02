#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

void solve() {
	int n; cin >> n;
	int prefix_XOR[n + 1], one = 0, zero = 0;
	int a[n + 1];
	prefix_XOR[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefix_XOR[i] = a[i] ^ prefix_XOR[i - 1];
	}
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') one ^= a[i + 1];
		else zero ^= a[i + 1];
	}
	int q; cin >> q;
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int x, y; cin >> x >> y;
			int range_XOR = prefix_XOR[y] ^ prefix_XOR[x - 1];
			one ^= range_XOR;
			zero ^= range_XOR;
		}
		else {
			int bit; cin >> bit;
			if (bit == 0) cout << zero << ' ';
			else cout << one << ' ';
		}
	}
	cout << '\n';
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
