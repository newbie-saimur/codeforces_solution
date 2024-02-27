#include <bits/stdc++.h>
using namespace std;
#define int    long long
int _;

struct info {
    int full = 0, open = 0, close = 0;
};

info merge(info &a, info &b) {
    info ans;
    ans.full = a.full + b.full + min(a.open, b.close);
    ans.open = a.open + b.open - min(a.open, b.close);
    ans.close = a.close + b.close - min(a.open, b.close);
    return ans;
}

void build(int index, int low, int high, string &a, info seg[]) {
    if (low == high) {
        seg[index].full = 0;
        seg[index].open = a[low] == '(';
        seg[index].close = a[low] == ')';
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid, a, seg);
    build(2 * index + 2, mid + 1, high, a, seg);
    seg[index] = merge(seg[2 * index + 1], seg[2 * index + 2]);
}

info query(int index, int low, int high, int l, int r, info seg[]) {
    if (low >= l && high <= r) return seg[index];
    if (low > r || high < l) return info();
    int mid = (low + high) / 2;
    info left = query(2 * index + 1, low, mid, l, r, seg);
    info right = query(2 * index + 2, mid + 1, high, l, r, seg);
    return merge(left, right);
}

void solve()
{
    string s; cin >> s;
    int n = s.size();
    info seg[4 * n];
    build(0, 0, n - 1, s, seg);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        info ans = query(0, 0, n - 1, l, r, seg);
        cout << ans.full * 2 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    // cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
