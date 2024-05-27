#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    vector<ll> x(n),y(n),r(n);
    rep(i,n) cin >> x[i] >> y[i] >> r[i];
    vector<vector<ll> > dist(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            ll d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            dist[i][j] = d;
        }
    }
    dsu uf(n*n);
    rep(i,n){
        rep(j,n){
            if(abs(r[i]-r[j])*abs(r[i]-r[j]) <= dist[i][j] && dist[i][j]<=(r[i]+r[j])*(r[i]+r[j])){
                uf.merge(i,j);
            }
        }
    }
    vector<int> sc,tc;
    rep(i,n){
        if((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy) == r[i]*r[i]){
            sc.push_back(i);
        }
    }
    rep(i,n){
        if((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty) == r[i]*r[i]){
            tc.push_back(i);
        }
    }
    rep(i,sc.size()){
        rep(j,tc.size()){
            if(uf.same(sc[i],tc[j])){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}