#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using T = tuple<ll,int,int>;

void chmin(ll& a, ll b){a = min(a,b);}

int main(){
    int n,m;
    cin >> n >> m;
    vector<T> es;
    const ll INF = 1e18;
    vector dist(n,vector<ll>(n,INF));
    rep(i,m){
        int a,b; ll t;
        cin >> a >> b >> t;
        a--; b--;
        chmin(dist[a][b],t);
        chmin(dist[b][a],t);
        es.emplace_back(t,a,b);
    }
    rep(i,n) dist[i][i] = 0;
    rep(k,n)rep(i,n)rep(j,n){
        chmin(dist[i][j],dist[i][k]+dist[k][j]);
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> bs(k);
        vector<int> is;
        rep(i,k) cin >> bs[i],bs[i]--;
        rep(i,k) is.push_back(i);
        ll ans = INF;
        do{
            // auto dfs = [&](auto dfs, int v, vector<int> vs)->void{
            //     if(v == k){
            //         ll cost = 0;
            //         int prev = 0;
            //         rep(i,k){
            //             if(vs[i] >= m){
            //                 auto [ti,ai,bi] = es[vs[i]-m];
            //                 swap(ai,bi);
            //                 cost += dist[prev][ai];
            //                 cost += ti;
            //                 prev = bi;
            //             }else{
            //                 auto [ti,ai,bi] = es[vs[i]];
            //                 cost += dist[prev][ai];
            //                 cost += ti;
            //                 prev = bi;
            //             }
            //         }
            //         cost += dist[prev][n-1];
            //         chmin(ans,cost);
            //         return;
            //     }
            //     vs.push_back(bs[is[v]]);
            //     dfs(dfs,v+1,vs);
            //     vs.pop_back();
            //     vs.push_back(bs[is[v]]+m);
            //     dfs(dfs,v+1,vs);
            // };
            // dfs(dfs,0,{});
            int k2 = 1<<k;
            rep(i,k2){
                ll cost = 0;
                int prev = 0;
                rep(j,k){
                    auto [ti,ai,bi] = es[bs[is[j]]];
                    if((i>>j)&1){
                        cost += dist[prev][ai];
                        cost += ti;
                        prev = bi;
                    }else{
                        cost += dist[prev][bi];
                        cost += ti;
                        prev = ai;
                    }
                }
                chmin(ans,cost+dist[prev][n-1]);
            }
        }while(next_permutation(is.begin(),is.end()));
        cout << ans << endl;
    }
    return 0;
}