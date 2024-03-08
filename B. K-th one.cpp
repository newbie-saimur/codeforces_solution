#include <bits/stdc++.h>
using namespace std;
#define int   long long
int _;

struct SGTree {
    int n;
    vector<int> seg;
    SGTree(int size) {
        n = size;
        seg.resize(4 * n);
    }
    int NUTRAL_ELEMENT = 0;
    int single(int x) {
        return x;
    }

    int calc(int left, int right) {
        return left + right;
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

    int query(int index, int low, int high, int k) {
        if (high == low) {
            return low - 1;
        }
        int mid = (low + high) / 2;
        int left = seg[2 * index];
        if (left >= k) return query(2 * index, low, mid, k);
        else return query(2 * index + 1, mid + 1, high, k - left);
    }

    int query(int k) {
        return query(1, 1, n, k);
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
    SGTree seg(n);
    seg.build(a);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int ind; cin >> ind;
            ind++;
            a[ind] ^= 1;
            seg.update(ind, a[ind]);
        }
        else {
            int k; cin >> k;
            cout << seg.query(k + 1) << '\n';
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
