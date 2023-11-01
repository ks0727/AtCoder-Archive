#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int t;
    cin >> t;
    const int MX = 3e6;
    auto f = [&](ll n)->pair<ll,ll>{
        pair<ll,ll> ans;
        for(int i = 2;i<(MX);i++){
            if(n%i != 0) continue;
            n/=i;
            if(n%i == 0){
                ans.first = (ll)i;
                ans.second = (ll)n/i;
                return ans;
            }else{
                ans.first = (ll)sqrt(n);
                ans.second = (ll)i;
                return ans;
            }
        }
        return ans;
    };
    rep(i,t){
        ll n;
        cin >> n;
        pair<ll,ll> ans = f(n);
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}