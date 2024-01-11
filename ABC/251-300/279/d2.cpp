#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll a,b;
    cin >> a >> b;
    auto calc = [&](ll x){
        if(x < 0) return 1e18;
        return (double)a/(sqrt(1+x))+ (double)x*b;
    };
    ll x = pow(2.*b/a,-2./3.);
    double ans = a;
    rep(i,200){
        ans = min(ans,calc(x+i-100));
    }
    printf("%.10lf\n",ans);
    return 0;
}