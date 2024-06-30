#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> pos,neg;
    rep(i,n){
        if(s[i] == '1') pos.push_back(x[i]);
        else neg.push_back(x[i]);
    }
    if(pos.size() == 0 || neg.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    ll negl = 0;
    ll negr = 0;
    ll ans = 0;
    ll t2 = (ll)t*2;
    for(auto p : pos){
        while (negl < neg.size() && p > neg[negl]) negl++;
        while(negr < neg.size() && p+t2 >= neg[negr]) negr++;
        ans += negr - negl;
    }
    cout << ans << endl;
    return 0;
}