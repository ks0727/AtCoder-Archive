#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;
const int di[] = {2,1,-1,-2,-2,-1,1,2};
const int dj[] = {1,2,2,1,-1,-2,-2,-1};

int main(){
    ll n,m;
    cin >> n >> m;
    set<P> st;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        st.insert(P(a,b));
        rep(d,8){
            int na = a + di[d];
            int nb = b + dj[d];
            if(na< 0 || nb < 0 || na >= n || nb >=n) continue;
            st.insert(P(na,nb));
        }
    }
    ll ans = (ll)n*n;
    ans -= (ll)st.size();
    cout << ans << endl;
    return 0;
}