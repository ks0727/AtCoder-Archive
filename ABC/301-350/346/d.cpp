#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<ll> right1(n+1),left1(n+1),right2(n+1),left2(n+1);
    ll rs = 0;
    ll ls = 0;
    vector<ll> diffr(n),diffl(n); 
    rep(i,n){ //左が0から始まる
        if(i%2 == 0 && s[i] == '1') diffr[i] = c[i];
        else if(i%2 == 1 && s[i] == '0') diffr[i] = c[i];
    }
    rep(i,n){
        if(i%2 == 0 && s[i] == '0') diffl[i] = c[i];
        else if(i%2 == 1 && s[i] == '1') diffl[i] = c[i];
    }
    rep(i,n+1) right2[i+1] = diffr[i] + right2[i];
    rep(i,n+1) left1[i+1] = diffl[i] + left1[i];
    reverse(diffr.begin(),diffr.end());
    reverse(diffl.begin(),diffl.end());
    rep(i,n+1) right1[i+1] = diffr[i] + right1[i];
    rep(i,n+1) left2[i+1] = diffl[i] + left2[i];
    const ll INF = 1e18;
    ll ans = INF;
    rep(i,n){
        ans = min(ans,left1[i]+right1[i+1]);
        ans = min(ans,left2[i]+right2[i+1]);
    }
    return 0;
}