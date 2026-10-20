#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1 だったら素数、 0 だったら素数でない
//計算量は O(NloglogN) くらいらしい
void tt(vector<int> &vec){
    vec[0] = 0; vec[1] = 0;

    for(ll i = 2; i < vec.size(); i++){
        if(vec[i] == 0)  continue;

        ll x = i + i;
        while(x < (ll)vec.size()){
            vec[x] = 0;
            x += i;
        }
    }
}

int main(){
    
}
