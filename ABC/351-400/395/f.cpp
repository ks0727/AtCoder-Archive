#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; long long x;
    cin >> n >> x;
    vector<long long> u(n),d(n);
    rep(i,n) cin >> u[i] >> d[i];

    long long l = 0, r = 1e18;
    while(r-l>1){
        long long mid = (l+r)/2;
        auto f = [&](long long m){
            long long mn = m-d[0];
            long long mx = u[0];
            if(mn > mx) return false;
            for(int i=1;i<n;i++){
                long long cmn = m-d[i];
                long long cmx = u[i];
                long long nmn = max(mn-x,cmn);
                long long nmx = min(mx+x,cmx);
                if(nmn > nmx) return false;
                mn = nmn; mx = nmx;
            }
            return true;
        };
        if(f(mid)) l = mid;
        else r = mid;
    }
    long long ans = 0;
    rep(i,n) ans += u[i]+d[i] - l;
    cout << ans << endl;
    return 0;
}