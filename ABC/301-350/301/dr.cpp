#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll pow(int a,int b){
    ll ans = 1;
    rep(i,b) ans *= a;
    return ans;
}

bool ok(string s, int v, ll n){
    rep(i,s.size()){
        if(i == v) s[i] = '1';
        if(i > v && s[i] == '?'){
            s[i] = '0';
        }
    }
    ll ans = 0;
    rep(i,s.size()){
        ans = ans*2 + s[i] - '0';
    }
    if(ans <= n) return true;
    else return false;
}

int main(){
    string s;
    cin >> s;
    ll n;
    cin >> n;
    ll ans = 0;
    string t = s;
    rep(i,t.size()){
        if(t[i] == '?'){
            t[i] = '0';
        }
        ans = ans * 2 + t[i] - '0';
    }
    if(ans > n){
        cout << -1 << endl;
        return 0;
    }
    ans = 0;
    rep(i,s.size()){
        if(s[i] == '?'){
            if(ok(s,i,n)){
                s[i] = '1';
            }else{
                s[i] = '0';
            }
        }
    }
    rep(i,s.size()){
        ans = ans*2 + s[i] - '0';
    }
    cout << ans << endl;
    return 0;
}