#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    n--;
    string s = "";
    while(n > 4){
        ll x = n % 5;
        n /= 5;
        s += to_string(x);
    }
    s += to_string(n);
    reverse(s.begin(),s.end());
    string a = "02468";
    string ns = "";
    rep(i,s.size()){
        ns += a[s[i]-'0'];
    }
    ll ans = stoll(ns);
    cout << ans << endl;
    return 0;
}