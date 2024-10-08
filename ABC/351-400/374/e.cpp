#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n),p(n),b(n),q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll r = 1e18,l=-1;
    while(r-l>1){
        ll mid = (r+l)/2;
        ll now = 0;
        rep(i,n){
            ll need = mid;
            ll lc = lcm(a[i],b[i]);
            if(a[i]*q[i] > b[i]*p[i]){
                now += need/lc*(lc/a[i])*p[i];
                need %= lc;
                if(need == 0) continue;
                now += min((need+a[i]-1)/a[i]*p[i],(need+b[i]-1)/b[i]*q[i]);
            }else{
                now += need/lc*(lc/b[i])*q[i];
                need %= lc;
                if(need == 0) continue;
                now += min((need+a[i]-1)/a[i]*p[i],(need+b[i]-1)/b[i]*q[i]);
            }
        }
        if(now < 0){
            cout << 0 << endl;
            return 0;
        }
        if(now > x) r = mid;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}