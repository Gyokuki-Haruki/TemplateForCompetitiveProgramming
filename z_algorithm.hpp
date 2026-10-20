#include <bits/stdc++.h>
using namespace std;
//Z algorithm（Zアルゴリズム）とは、ある文字列の
//「先頭部分（プレフィックス）」と「文字列内の各位置から始まる部分」が、
//どこまで一致しているかをすべて高速（一瞬）で調べるためのアルゴリズム
vector<int> z_algorithm(const string& s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<r) z[i]=min(r-i,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}
