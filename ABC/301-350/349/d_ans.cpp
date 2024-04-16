#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int main(){
    ll L,R; cin >> L >> R;
    vector<pair<ll,ll> > ans;
    while (L < R){
        for(int i=60;i>=0;i--){
            ll w = 1ll<<i;
            if(L%w) continue;
            if(L+w > R) continue;
            ans.emplace_back(L,L+w);
            L += w;
            break;
        }
    }
    cout <<ans.size() << endl;
    for(auto[l,r] : ans) cout << l << ' ' << r << endl;
    return 0;
}