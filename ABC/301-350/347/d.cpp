#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

string dtob(ll x){
    string res = "";
    while(x > 0){
        res += (x%2) + '0';
        x /= 2;
    }
    //reverse(res.begin(),res.end());
    return res;
}
ll btod(string s){
    ll res = 0;
    rep(i,s.size()){
        res = res * 2 + s[i]-'0';
    }
    return res;
};
int main(){
    int a,b; ll c;
    cin >> a >> b >> c;
    string s = dtob(c);
    int n = __builtin_popcount(c);
    int m = s.size();
    int needed_a = -1, needed_b = -1;
    rep(i,n+1){
        int cnta = i,cntb = n-i;
        if(a-cnta == b - cntb){
            needed_a = cnta;
            needed_b =  cntb;
            break;
        }
    }
    cout << needed_a << ' ' << needed_b << endl;
    if(needed_a == -1) cout << -1 << endl;
    else{
        string ans_a = "";
        string ans_b = "";
        rep(i,needed_a) ans_a += '1';
        rep(i,n-needed_a) ans_a += '0';
        rep(i,n){
            if(ans_a[i] == '1') ans_b += '0';
            else ans_b += '1';
        }
        reverse(ans_a.begin(),ans_a.end());
        reverse(ans_b.begin(),ans_b.end());
        rep(i,a-needed_a){
            ans_a += '1';
            ans_b += '1';
        }
        reverse(ans_a.begin(),ans_a.end());
        reverse(ans_b.begin(),ans_b.end());
        cout << ans_a << endl;
        cout << ans_b << endl;
        ll aa =btod(ans_a), bb = btod(ans_b);
        cout << aa << ' ' << bb << endl;
    }
    return 0;
}