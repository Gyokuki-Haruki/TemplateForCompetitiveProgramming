#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> S;
    int x = 0;
    S.insert(x);      // 追加
    S.erase(x);       // 削除
    S.count(x);       // 存在判定
    S.find(x);        // 検索
    S.lower_bound(x); // x以上最小 インテレータみたいなやつだから注意だね
    S.upper_bound(x); // xより大きい最小
    S.size();         // 要素数
    S.begin();        // 最小要素
    prev(S.end());    // 最大要素
}
