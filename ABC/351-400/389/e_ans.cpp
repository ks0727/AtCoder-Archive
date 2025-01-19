#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; long long m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    long long l=1,r=m+1;
    long long tot = 0, num = 0;
    auto f = [&](long long x){
        tot = 0; num = 0;
        rep(i,n){
            long long k = ((x-1)/p[i]+1)/2;
            if(k == 0) continue;
            if(m/k/k/p[i] == 0) return false;
            tot += k*k*p[i];
            num += k;
            if(tot > m) return false; 
        }
        return true;
    };
    while(r-l>1){
        long long mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    f(r);
    num += (m-tot)/r;
    cout << num << endl;
    return 0;
}