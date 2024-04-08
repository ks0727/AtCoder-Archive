#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    const ll INF = 5e18+1;
    vector<ll> sizeSubtree(n,INF);
    int x = -1;
    ll tot = 0;
    rep(i,n) tot += c[i];
    auto FindCentroid = [&](auto FindCentroid, int v, int p=-1)->void{ //Find the centroid of the tree
        sizeSubtree[v] = c[v];
        bool isCentroid = true;
        ll mx = 0;
        for(auto ch : g[v]){
            if(ch == p) continue;
            FindCentroid(FindCentroid,ch,v);
            mx = max(mx,sizeSubtree[ch]);
            if(sizeSubtree[ch]*2 > tot) isCentroid = false;
            sizeSubtree[v] += sizeSubtree[ch];
        }
        mx = max(mx,tot-sizeSubtree[v]);
        if(mx*2 > tot) isCentroid = false;
        if(isCentroid) x = v;
    };
    FindCentroid(FindCentroid,0);
    ll ans = 0;
    auto dfs = [&](auto dfs, int v,int p=-1,int dist=0)->void{
        ans += (ll)dist*c[v];
        for(int ch : g[v]){
            if(ch == p) continue;
            dfs(dfs,ch,v,dist+1);
        }
    };
    dfs(dfs,x);
    cout << ans << endl;
}