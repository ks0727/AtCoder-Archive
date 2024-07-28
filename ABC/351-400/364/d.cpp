#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    rep(qi,q){
        int b,k;
        cin >> b >> k;
        ll l = -1, r = max(abs(b-a[0]),abs(b-a[n-1]))+1;
        int bx = lower_bound(a.begin(),a.end(),b) - a.begin();
        while(r > l+1){
            ll mid = (l+r)/2;
            auto f = [&](int m, int k){
                ll right = b + m;
                ll left = b - m;
                int rx = upper_bound(a.begin(),a.end(),right) - a.begin();
                int lx = lower_bound(a.begin(),a.end(),left) - a.begin();
                //cout << right << ' ' << left << ' ' << rx << ' ' << lx << endl;
                if(rx-lx >= k) return true;
                else return false;
            };
            if(f(mid,k)) r = mid;
            else l = mid;
        }
        cout <<r << endl;
    }
    return 0;
}