#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;

//prime_factorize(素因数分解)
vector<P> pf(ll n){
    vector<P> res;
    for(ll a = 2;a*a <= n;a++){
        if(n % a != 0)  continue;
        int ex = 0; //指数
        while(n%a == 0){
            ex++;
            n /= a;
        }
        res.emplace_back(a,ex);
    }
    if(n != 1) res.emplace_back(n,1);
    return res;
}

int main(){
    ll k;
    cin >> k;
    vector<P> pfs = pf(k);
    ll ans = 1;
    for(auto pf : pfs){
        auto [p,ex] = pf;
        ll now = 0;
        ll i = 0;
        ll num = 0;
        while(now < (ll)ex){
            i++;
            num = (ll)p * i;
            ll cnt = 0;
            ll num2 = num;
            while(true){
                if(num2 % p != 0) break;
                cnt++;
                num2 /= p;
            }
            now+= cnt;
        }
        ans = max(ans,num);
    }
    cout << ans << endl;
    return 0;
}