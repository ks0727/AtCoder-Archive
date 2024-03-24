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
    vector<ll> diff0(n),diff1(n);
    rep(i,n){
        if(i%2 == 0 && s[i] == '1') diff0[i] += c[i];
        if(i%2 == 1 && s[i] == '0') diff0[i] += c[i];
        if(i%2 == 0 && s[i] == '0') diff1[i] += c[i];
        if(i%2 == 1 && s[i] == '1') diff1[i] += c[i];
    }
    vector<ll> right0(n+1),left0(n+1),right1(n+1),left1(n+1);
    rep(i,n) left1[i+1] = left1[i]+diff1[i];
    rep(i,n) left0[i+1] = left0[i]+diff0[i];
    reverse(diff0.begin(),diff0.end());
    reverse(diff1.begin(),diff1.end());
    left0.pop_back();
    left1.pop_back();
    rep(i,n) right1[i+1] = right1[i]+diff1[i];
    rep(i,n) right0[i+1] = right0[i]+diff0[i];
    const ll INF = 9e18;
    ll ans = INF;
    reverse(right0.begin(),right0.end());
    reverse(right1.begin(),right1.end());
    right0.pop_back();
    right1.pop_back();
    // rep(i,n) cout << left1[i] << ' '; cout << endl; 
    // rep(i,n) cout << right0[i] << ' '; cout << endl; 
    // rep(i,n) cout << left0[i] << ' '; cout << endl; 
    // rep(i,n) cout << right1[i] << ' '; cout << endl; 
    for(int i=0;i<(n);i++){
        ans = min(ans,left1[i]+right0[i]);
        ans = min(ans,left0[i]+right1[i]);
    }
    cout << ans << endl;
    return 0;
}