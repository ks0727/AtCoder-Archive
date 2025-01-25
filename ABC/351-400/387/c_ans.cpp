#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll pw(ll x, int p){
    ll res = 1;
    rep(i,p) res *= x;
    return res;
}

ll f(ll r){
    vector<int> digits;
    for(char c : to_string(r)){
        digits.push_back(c-'0');
    }
    int n = digits.size();
    ll res = 0;
    //まずn桁より小さい桁の時を考える
    for(int k=1;k<n;k++){
        for(int h=1;h<=9;h++) res += pw(h,k-1);
    }
    //n桁の数について考える(先頭が小さい)
    for(int h=1;h<digits[0];h++) res += pw(h,n-1);
    int h = digits[0];
    for(int i=1;i<n;i++){
        if(digits[i] > h){ //この桁以降はヘビ数ではないので終わる
            res += pw(h,n-i);
            break;
        }
        res += pw(h,n-i-1)*digits[i];
    }
    return res;
}

int main(){
    ll l,r;
    cin >> l >> r;
    ll ans = f(r) - f(l-1);
    cout << ans << endl;
    return 0;
}