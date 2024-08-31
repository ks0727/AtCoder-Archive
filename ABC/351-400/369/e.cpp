#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using T = tuple<ll,ll,ll>;
using P = tuple<ll,int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<T> es;
    const ll INF = 1e18;
    vector<vector<P> > g(n);
    rep(i,m){
        int a,b; ll t;
        cin >> a >> b >> t;
        a--; b--;
        es.emplace_back(t,a,b);
        g[a].emplace_back(t,b,i);
        g[b].emplace_back(t,a,i);
    }
    rep(i,n) sort(g[i].begin(),g[i].end());
    int q;
    cin >> q;
    while(q--){
        int k; cin >> k;
        ll ans = 0;
        vector<int> need;
        rep(ki,k){
            int b;
            cin >> b;
            b--;
            need.push_back(b);
        }
        set<int> st;
        auto f = [&](auto f, int v)->void{
            if(v == n-1){
                rep(i,k){
                    if(!st.count(need[i])) break;
                    if(i == k-1){
                        return;
                    }
                }
            }

                for(auto [t,u,i] : g[v]){
                    
                }
        };
        cout << ans << '\n';
    }
    return 0;
}