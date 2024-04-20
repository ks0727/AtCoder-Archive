#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n; int a,x,y;
    cin >> n >> a >> x >> y;
    map<ll,double> memo;
    auto f = [&](auto f, ll z)->double{
        if(z == 0) return memo[0] = 0;
        if(memo.count(z)) return memo[z];
        double fir = x + f(f,z/a);
        double sec = ((double)y*6./5+1./5*f(f,z/6)+1./5*f(f,z/5)+1./5*f(f,z/4)+1./5*f(f,z/3)+1./5*f(f,z/2));
        double res = min(fir,sec);
        return memo[z] = res;
    };
    double ans = f(f,n);
    printf("%.10f\n",ans);
    return 0;
}