#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> d(n-1);
    rep(i,n-1) d[i] = a[i+1]-a[i];
    stack<P> st;
    st.push(P(-1001001001,0));
    rep(i,n-1){
        auto [v,cnt] = st.top();
        if(v == d[i]){
            st.pop();
            st.push(P(v,cnt+1));
        }else{
            st.push(P(d[i],1));
        }
    }
    ll ans = n;
    while(!st.empty()){
        auto [v,cnt] = st.top(); st.pop();
        ans += (ll)(cnt)*(cnt+1)/2;
    }
    cout << ans << endl;
    return 0;
}