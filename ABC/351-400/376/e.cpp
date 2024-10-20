#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;
const ll INF = 1e18;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<P> ps(n);
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    multiset<int> st;
    rep(i,n){
        ps[i] = P(a[i],b[i]);
        st.insert(b[i]);
    } 
    sort(b.begin(),b.end());
    sort(ps.rbegin(),ps.rend());
    ll now = INF;
    ll sum = 0;
    auto it = st.begin();
    rep(i,k){
        sum += *it;
        it++;
    } 
    cout << sum << endl;
    return;
    //rep(i,k) sum += b[i];
    //int bidx = k-1;
    rep(i,n-k+1){
        if(ps[i].second > *it){
            now = min(now,(sum-*it+ps[i].second)*ps[i].first);
        }else{
            now = min(now,sum*ps[i].first);
            sum -= ps[i].second;
            it++;
            sum += *it;
        }
    }
    cout << now << '\n';
    return;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}