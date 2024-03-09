#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int m;
    cin >> m;
    vector<ll> b(m);
    rep(i,m) cin >> b[i];
    int l;
    cin >> l;
    vector<ll> c(l);
    rep(i,l) cin >> c[i];
    unordered_set<ll> st;
    rep(i,n){
        rep(j,m){
            rep(k,l){
                st.insert(a[i]+b[j]+c[k]);
            }
        }
    }
    int q;
    cin >> q;
    rep(qi,q){
        ll x;
        cin >> x;
        if(st.count(x)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}