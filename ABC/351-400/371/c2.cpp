#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<set<int> > g(n+1),h(n+1);
    int mg;
    cin >> mg;
    vector<vector<bool> > gc(n+1,vector<bool>(n+1));
    vector<vector<bool> > hc(n+1,vector<bool>(n+1));
    rep(i,mg){
        int u,v;
        cin >> u >> v;
        //u--; v--;
        g[u].insert(v);
        g[v].insert(u);
        hc[u][v] = true;
        hc[v][u] = true;
    }
    int mh;
    cin >> mh;
    rep(i,mh){
        int a,b;
        cin >> a >> b;
        //a--; b--;
        h[a].insert(b);
        h[b].insert(a);
        hc[a][b] = true;
        hc[b][a] = true;
    }
    vector<vector<int> > a(n+1,vector<int>(n+1));
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++) cin >> a[i][j];
    }
    rep(i,n+1){
        rep(j,n+1) cout << a[i][j] << ' ';
        cout << endl;
    }
    vector<int> id(n);
    for(int i=1;i<=n;i++) id[i-1] = i;
    ll ans = 1e18;
    do{
        ll now = 0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if(id[i] == 0 || id[j] == 0) continue;
                if(g[i].count(j) && !h[id[i]].count(id[j])){
                    if(a[id[i]][id[j]-1] != 0) now += a[id[i]][id[j]-1];
                    else now += a[id[j]][id[i]-1];
                }
                else if(!g[i].count(j) && h[id[i]].count(id[j])){
                    if(a[id[i]][id[j]-1] != 0 )now += a[id[i]][id[j]-1];
                    else now += a[id[j]][id[i]-1];
                }
            }
        }
        ans = min(ans,now);
    }while(next_permutation(id.begin(),id.end()));
    cout << ans << endl;
    return 0;
}