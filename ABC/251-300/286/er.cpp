#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    const ll INF = 1e18;
    vector<vector<ll> > d(n,vector<ll>(n,INF));
    vector<vector<ll> > sou(n,vector<ll>(n,0));
    
    rep(i,n){
        rep(j,n){
            if(i == j){
                d[i][j] = 0;
                sou[i][j] = 0;
            }
            if(s[i][j] == 'Y'){
                d[i][j] = 1;
                sou[i][j] = (ll)a[j];
            }
        }
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if((d[i][k]+d[k][j])<d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    sou[i][j] = sou[i][k]+sou[k][j];
                }
                else if((d[i][k]+d[k][j])==d[i][j]) sou[i][j] = max(sou[i][j],sou[i][k]+sou[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    rep(qi,q){
        int u,v;
        cin >> u >> v;
        u--; v--;
        if(d[u][v] == INF) cout << "Impossible" << '\n';
        else cout << d[u][v] << ' ' << sou[u][v]+(ll)a[u] << '\n';
    }
    return 0;
}