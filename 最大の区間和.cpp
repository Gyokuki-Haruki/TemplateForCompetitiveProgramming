#include <bits/stdc++.h>
using namespace std;
int main(){
    //best が最大の区間和
    //ansL, ansR はその区間和の初めと終わり
    //Kadane法 を利用している
    vector<int> vec(10, 0);
    long long best = -(1LL<<60);
    long long now = 0;
    int l = 0;          // 現在の区間の左端候補
    int ansL = 0, ansR = 0;
    int N = vec.size();
    for(int i = 0; i <= N; i++){
        if(now <= 0){
            now = vec[i];
            l = i;
        }
        else{
            now += vec[i];
        }
        if(now > best){
            best = now;
            ansL = l;
            ansR = i;
        }
    }
}