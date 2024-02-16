#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;
using mint = modint998244353;

int main(){
    int n,m;
    cin >> n >> m;
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    set<P> st;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        st.emplace(x,y);
    }
    map<P,mint> mp;
    auto memo = [&](auto memo, P pos, int depth)->mint{
        if(depth == n) return 1;
        if(mp.count(pos)) return mp[pos];
        else{
            P np1,np2,np3;
            np1 = P(pos.first+a,pos.second+b);
            np2 = P(pos.first+c,pos.second+d);
            np3 = P(pos.first+e,pos.second+f);
            mint res = 0;
            if(!st.count(np1)) res += memo(memo,np1,depth+1);
            if(!st.count(np2)) res += memo(memo,np2,depth+1);
            if(!st.count(np3)) res += memo(memo,np3,depth+1);
            return mp[pos] = res;
        }
    };
    mint ans = memo(memo,P(0,0),0);
    cout << ans.val() << endl;
    return 0;
}
