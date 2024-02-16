#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll p,q,r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1);
    rep(i,n) sum[i+1] = a[i] + sum[i];
    set<ll> st;
    rep(i,n+1) st.insert(sum[i]);
    bool ans = false;
    for(ll x : st){
        if(!st.count(x+p)) continue;
        if(!st.count(x+p+q)) continue;
        if(!st.count(x+p+q+r)) continue;
        ans = true;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}