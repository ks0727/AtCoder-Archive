#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;



int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> p(n-1),t(n-1);
    rep(i,n-1) cin >> p[i] >> t[i];
    int q;
    cin >> q;
    int mx = -1;
    rep(i,n-1) mx = max(mx,p[i]);
    //以下ゼロの時のシュミレーション
    ll zero = 0;
    zero += x;
    rep(i,n-1){
        ll k = (zero+p[i]-1)/p[i];
        zero = (ll)p[i]*k;
        zero += t[i];
    }
    zero += y;
    while(q--){
        int qi;
        cin >> qi;
        qi += x;
        int l = qi/mx;
        if(l != 0) l--;
        cout << (ll)zero+(ll)mx*l << endl;
    }
    return 0;
}