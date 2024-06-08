#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    const int M = 1e6;
    int n;
    cin >> n;
    vector<int> c(M+1);
    rep(i,n){
        int a;
        cin >> a;
        c[a]++;
    }
    vector<int> s(M+1);
    rep(i,M) s[i+1] = s[i]+c[i];
    auto sum = [&](int l,int r){
        r = min(M,r);
        return s[r]-s[l];
    };

    ll ans = 0;
    for(int y=1;y<=M;y++){
        ll now = 0;
        for(int x = 1;x*y<=M;x++){
            ll l = y*x;
            ll r = y*(x+1);
            now += sum(l,r)*x;
        }
        now -= c[y];
        ans += now*c[y];
        ans += (ll)c[y]*(c[y]-1)/2;
    }
    cout << ans << endl;
    return 0;
}