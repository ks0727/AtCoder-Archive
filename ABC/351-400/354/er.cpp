#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    int n2 = 1<<n;
    vector<bool> dp(n2);

    rep(s,n2){
        rep(i,n){
            rep(j,n){
                if(i == j) continue;
                if(!(s&(1<<i))) continue; //iビット目が立っていなかったらだめ
                if(!(s&(1<<j))) continue; //jビット目が立っていなかったらだめ
                if(a[i] == a[j] || b[i] == b[j]){
                    if(!dp[s&~(1<<i)&~(1<<j)]) dp[s] = true; //今あるカードからi番目とj番目を使った時に, 相手が必敗ならばそのターンの人は必勝となる
                }
            }
        }
    }

    if(dp[n2-1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}