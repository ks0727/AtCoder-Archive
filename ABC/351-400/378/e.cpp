#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),s(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) s[i+1] = s[i]+a[i];
    rep(i,n+1) s[i]%=m;
    ll ans = 0;
    multiset<ll> st;
    rep(i,n+1){
        if(i == 0){
            st.insert(s[i]);
            continue;
        }
        ll pos = i;
        ll neg = n+1-i;
        ans -= neg*s[i];
        ll bigger = distance(st.upper_bound(s[i]),st.end());
        ans += bigger*(s[i]+m);
        ans += s[i]*(pos-bigger+1);
        st.insert(s[i]);
    }
    cout << ans << endl;
    return 0;
}