#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n,a,x,y;
    cin >> n >> a >> x >> y;
    map<ll,double> memo;
    auto f = [&](auto f, ll x)->double{
        if(x == 0) return 0;
        if(memo.count(x)) return memo[x];
        double res = f(f,x/a) + x;
        double dice = 0;
        for(int i=2;i<=6;i++){
            dice += f(f,n/i);
        }
        dice /= 5;
        dice += y*6/5.;
        res = min(res,dice);
        return memo[x] = res;
    };
    double ans = f(f,n);
    printf("%.10f",ans);
    return 0;
}