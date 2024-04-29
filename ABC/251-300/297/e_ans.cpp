#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll= long long;

int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<ll> st;
    auto push = [&](ll x){
        rep(i,n){
            ll nx = x+a[i];
            st.insert(nx);
        }
    };
    push(0);
    rep(i,k-1){
        ll x = *st.begin();
        st.erase(x);
        push(x);
    }
    ll ans = *st.begin();
    cout << ans << endl;
    return 0;
}