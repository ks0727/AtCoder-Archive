#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll a,b;
    cin >> a >> b;
    auto calc = [&](ll x){
        return (double)a/(sqrt(x+1))+ (double)b*x;
    };
    ll r = 1e18; ll l = 0;
    while(r - l > 1){
        ll middle = (l+r)/2;
        if(calc(middle) < calc(middle-1))l = middle;
        else r = middle;
    }
    double ans = a;
    ans = min(ans,calc(l));
    printf("%.10lf\n",ans);
    return 0;
}