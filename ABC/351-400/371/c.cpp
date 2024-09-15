#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<bool> > g(n,vector<bool>(n)),h(n,vector<bool>(n));
    int mg;
    cin >> mg;
    rep(i,mg){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = true;
        g[v][u] = true;
    }
    int mh;
    cin >> mh;
    rep(i,mh){
        int a,b;
        cin >> a >> b;
        a--; b--;
        h[a][b] = true;
        h[b][a] = true;
    }
    vector<vector<int> > a(n,vector<int>(n));
    rep(i,n-1){
        for(int j=i+1;j<n;j++) cin >> a[i][j];
    }
    vector<int> id;
    rep(i,n) id.push_back(i);
    ll ans = 1e18;
    do{
        ll now = 0;
        rep(i,n){
            for(int j=i+1;j<n;j++){
                if(g[i][j] && !h[id[i]][id[j]]){
                    int ni = id[i]; int nj = id[j];
                    if(ni > nj) swap(ni,nj); 
                    now += a[ni][nj];
                }
                if(!g[i][j] && h[id[i]][id[j]]){
                    int ni = id[i]; int nj = id[j];
                    if(ni > nj) swap(ni,nj); 
                    now += a[ni][nj];
                }
            }
        }
        ans = min(now,ans);
    }while(next_permutation(id.begin(),id.end()));
    cout << ans << endl;
    return 0;
}