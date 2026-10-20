#include <bits/stdc++.h>
using namespace std;
class UnionFind{
    public:
    int siz[200009];
    int par[200009];

    void init(int N){
        for(int i = 1; i <= N; i++){
            siz[i] = 1;
            par[i] = -1;
        }
    }

    int root(int X){
        while(true){
            if(par[X] == -1) break;
            X = par[X];
        }
        return X;
    }

    void update(int u, int v){
        int U = root(u);
        int V = root(v);
        if(U == V) return;
        if(siz[U] > siz[V]){
            siz[U] = siz[U] + siz[V];
            par[V] = U;
        }
        else{
            siz[V] = siz[U] + siz[V];
            par[U] = V;
        }
        return;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

UnionFind Z;
int main(){

}