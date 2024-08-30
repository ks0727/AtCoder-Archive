#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

vector<vector<ll> > matmul(vector<vector<ll> > a, vector<vector<ll> > b, ll mod){
    int n = a.size();
    vector<vector<ll> > res(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll> > matpow(vector<vector<ll> > a, ll b, ll mod){
    int n = a.size();
    vector<vector<ll> > res(n,vector<ll>(n));
    rep(i,n) res[i][i] = 1;
    while(b){
        if(b&1){
            res = matmul(res,a,mod);
            a = matmul(a,a,mod);
            b >>= 1;
        }
    }
    return res;
}

int main(){
    ll a,x,m;
    cin >> a >> x >> m;
    vector<vector<ll> >  f = {{a,1},{0,1}};
    vector<vector<ll> >  g = matpow(f,x,m);
    cout << g[0][1] << endl;
    return 0;
}