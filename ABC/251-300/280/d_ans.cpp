#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll f(ll n,ll p){
    if(n ==0) return 0;
    n /= p;
    return n+f(n,p);
}

int main(){
    ll k;
    cin >> k;
    vector<pair<ll,int> > ps;
    {
        ll x = k;
        for(ll i =2;i*i<=x;i++){
            if(x%i) continue;
            int cnt = 0;
            while(x % i == 0){
                x /= i;
                cnt++;
            }
            ps.emplace_back(i,cnt);
        }
        if(x != 1) ps.emplace_back(x,1);
    }
    ll r = k,l = 0;
    while(r-l>1){
        ll mid = (l+r)/2;
        bool ok = true;
        for(auto [p,cnt]:ps){
            if(f(mid,p) < cnt) ok = false;
        }
        if(ok) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}