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
    string s1,s2;
    rep(i,n){
        if(i%2 == 0){
            s1 += '0';
            s2 += '1';
        }else{
            s1 += '1';
            s2 += '0';
        } 
    }
    vector<ll> l1(n+1),l2(n+1),r1(n+1),r2(n+1);
    rep(i,n){
        if(s[i] == s1[i]) l1[i+1] = l1[i];
        else l1[i+1] = l1[i] + c[i];
        if(s[i] == s2[i]) l2[i+1] = l2[i];
        else l2[i+1] = l2[i] + c[i];
    }
    for(int i=n-1;i>=0;i--){
        if(s[i] == s1[i]) r1[i] = r1[i+1];
        else r1[i] = r1[i+1] + c[i];
        if(s[i] == s2[i]) r2[i] = r2[i+1];
        else r2[i] = r2[i+1] + c[i]; 
    }
    const ll INF = 1e18;
    ll ans = INF;
    for(int i=1;i<(n);i++){
        ans = min(ans,l1[i]+r2[i]);
        ans = min(ans,l2[i]+r1[i]);
    }
    cout << ans << endl;
    return 0;
}