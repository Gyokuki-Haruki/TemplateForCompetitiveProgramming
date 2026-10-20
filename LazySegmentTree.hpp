#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

class LazySegmentTree{
private:
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    void push(int k){
        if(lazy[k] == 0) return;
        if(k < n - 1){
            lazy[2 * k + 1] += lazy[k];
            tree[2 * k + 1] += lazy[k];
            lazy[2 * k + 2] += lazy[k];
            tree[2 * k + 2] += lazy[k];
        }
        lazy[k] = 0;
    }


public:
    LazySegmentTree(int size){
        n = 1;
        while(n < size) n *= 2;
        tree.assign(2 * n - 1, 0);
        lazy.assign(2 * n - 1, 0);
    }

    void add(int a, int b, long long x, long long k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(a >= r || b <= l) return;
        if(a <= l && r <= b){
            tree[k] += x;
            lazy[k] += x;
            return;
        }
        push(k);
        int mid = (l + r) / 2;
        add(a, b, x, 2 * k + 1, l, mid);
        add(a, b, x, 2 * k + 2, mid, r);
        tree[k] = max(tree[2 * k + 1], tree[2 * k + 2]);
    }

    long long get_max(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(a >= r || b <= l) return -INF;
        if(a <= l && r <= b) return tree[k];
        push(k);
        int mid = (l + r) / 2;
        long long vl = get_max(a, b, 2 * k + 1, l, mid);
        long long vr = get_max(a, b, 2 * k + 2, mid, r);
        return max(vl, vr);
    }

};

int main(){
    vector<long long> a = {5, 2, 8, 1, 3, 7, 4, 6};
    int n = a.size();
    LazySegmentTree seg(n);
    for(int i = 0; i < n; i++){
        seg.add(i, i + 1, a[i]);
    }
    seg.add(0, 4, 2);
    seg.add(2, 7, 4);
    cout << "区間[1, 7)の最大値:" << seg.get_max(1, 7) << endl;
    return 0;
}
