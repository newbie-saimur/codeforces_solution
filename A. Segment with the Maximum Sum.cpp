#include <bits/stdc++.h>
using namespace std;
#define int   long long
int _;

struct var {
    int max_sum, pref, suf, sum;
};

struct SGTree {
    vector<var> seg;
public:
    int n;
    SGTree(int size) {
        n = size;
        seg.resize(4 * n + 1);
    }

    var single(int x) {
        if (x > 0) return {x, x, x, x};
        else return {0, 0, 0, x};
    }

    var calc(var left, var right) {
        return {
            max({left.max_sum, right.max_sum, left.suf + right.pref}),
            max(left.pref, left.sum + right.pref),
            max(right.suf, left.suf + right.sum),
            left.sum + right.sum
        };
    }

    void build(int index, int low, int high, int a[]) {
        if (low == high) {
            seg[index] = single(a[low]);
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index, low, mid, a);
        build(2 * index + 1, mid + 1, high, a);
        seg[index] = calc(seg[2 * index], seg[2 * index + 1]);
    }

    void build(int a[]) {
        build(1, 1, n, a);
    }

    var query(int index, int low, int high, int l, int r) {
        if (low >= l && high <= r) return seg[index];
        if (low > r || high < l) return {0, 0, 0, 0};
        int mid = (low + high) / 2;
        var left = query(2 * index, low, mid, l, r);
        var right = query(2 * index + 1, mid + 1, high, l, r);
        return calc(left, right);
    }

    var query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    void update(int index, int low, int high, int i, int x) {
        if (low == high) {
            seg[index] = single(x);
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) update(2 * index, low, mid, i, x);
        else update(2 * index + 1, mid + 1, high, i, x);
        seg[index] = calc(seg[2 * index], seg[2 * index + 1]);
    }

    void update(int index, int value) {
        update(1, 1, n, index, value);
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SGTree seg(n + 1);
    seg.build(a);
    cout << seg.query(1, n).max_sum << '\n';
    while (q--) {
        int ind, val; cin >> ind >> val;
        seg.update(ind + 1, val);
        cout << seg.query(1, n).max_sum << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin>>test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
