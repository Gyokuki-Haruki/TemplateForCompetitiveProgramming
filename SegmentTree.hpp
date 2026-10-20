#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (1LL << 60);

// ====================
// Segment Tree : Max
// ====================
class SegmentTreeMax {
public:
    int siz;
    vector<ll> dat;

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;

        dat.assign(2 * siz, 0);
    }

    void update(int pos, ll x) {
        pos += siz;
        dat[pos] = x;

        while (pos > 1) {
            pos /= 2;
            dat[pos] = max(dat[2 * pos], dat[2 * pos + 1]);
        }
    }

    // [l, r)
    ll query(int l, int r, int a, int b, int u) {
        if (b <= l || r <= a) return 0;

        if (l <= a && b <= r) {
            return dat[u];
        }

        int m = (a + b) / 2;

        ll left = query(l, r, a, m, 2 * u);
        ll right = query(l, r, m, b, 2 * u + 1);

        return max(left, right);
    }

    ll query1(int l, int r) {
        return query(l, r, 0, siz, 1);
    }

};

// ====================
// Segment Tree : Min
// ====================
class SegmentTreeMin {
public:
    int siz;
    vector<ll> dat;

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;

        dat.assign(2 * siz, INF);
    }

    void update(int pos, ll x) {
        pos += siz;
        dat[pos] = x;

        while (pos > 1) {
            pos /= 2;
            dat[pos] = min(dat[2 * pos], dat[2 * pos + 1]);
        }
    }

    // [l, r)
    ll query(int l, int r, int a, int b, int u) {
        if (b <= l || r <= a) return INF;

        if (l <= a && b <= r) {
            return dat[u];
        }

        int m = (a + b) / 2;

        ll left = query(l, r, a, m, 2 * u);
        ll right = query(l, r, m, b, 2 * u + 1);

        return min(left, right);
    }

    ll query1(int l, int r) {
        return query(l, r, 0, siz, 1);
    }

};

// ====================
// Segment Tree : Sum
// ====================
class SegmentTreeSum {
public:
    int siz;
    vector<ll> dat;

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;

        dat.assign(2 * siz, 0);
    }

    void update(int pos, ll x) {
        pos += siz;
        dat[pos] = x;

        while (pos > 1) {
            pos /= 2;
            dat[pos] = dat[2 * pos] + dat[2 * pos + 1];
        }
    }

    // [l, r)
    ll query(int l, int r, int a, int b, int u) {
        if (b <= l || r <= a) return 0;

        if (l <= a && b <= r) {
            return dat[u];
        }

        int m = (a + b) / 2;

        ll left = query(l, r, a, m, 2 * u);
        ll right = query(l, r, m, b, 2 * u + 1);

        return left + right;
    }

    ll query1(int l, int r) {
        return query(l, r, 0, siz, 1);
    }

};

int main() {


}
