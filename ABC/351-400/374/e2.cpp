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
        ll nowa = 0;
        ll nowb = 0;
        ll need = mid;
        rep(i,n){
            nowa += (need/a[i])*p[i];
            need%=a[i];
            nowa += (need+b[i]-1)/b[i]*q[i];
            need = mid;
            nowb += (need/b[i])*q[i];
            need%=b[i];
            nowb += (need+a[i]-1)/a[i]*p[i];
            now += min(nowa,nowb);
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