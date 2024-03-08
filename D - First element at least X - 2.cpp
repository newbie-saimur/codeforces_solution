#include <bits/stdc++.h>
using namespace std;
#define int   long long
int _;

struct SGTree {
    int n;
    vector<pair<int, int>> seg;
    SGTree(int size) {
        n = size;
        seg.resize(4 * n);
    }

    pair<int, int> single(int x, int ind) {
        return {x, ind};
    }

    pair<int, int> calc(auto left, auto right) {
        int v = max(left.first, right.first);
        return {v, left.first == v ? left.second : right.second};
    }

    void build(int index, int low, int high, int a[]) {
        if (low == high) {
            seg[index] = single(a[low], low);
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

    int query(int index, int low, int high, int k, int x) {
        if (seg[index].first < k || high < x) return -1;
        if (high == low) {
            return seg[index].second - 1;
        }
        int mid = (low + high) / 2;
        int res = query(2 * index, low, mid, k, x);
        if (res == -1) res = query(2 * index + 1, mid + 1, high, k, x);
        return res;
    }

    int query(int k, int x) {
        return query(1, 1, n, k, x);
    }

    void update(int index, int low, int high, int i, int x) {
        if (low == high) {
            seg[index] = single(x, low);
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
    SGTree seg(n);
    seg.build(a);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int ind, val; cin >> ind >> val;
            ind++;
            a[ind] = val;
            seg.update(ind, a[ind]);
        }
        else {
            int k, ind; cin >> k >> ind;
            cout << seg.query(k, ind + 1) << '\n';
        }
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
