#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll dist(ll x1, ll y1, ll x2, ll y2){
    ll res = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return res;
}

int main(){
    int n; ll d;
    cin >> n >> d;
    vector<vector<ll> > D(n,vector<ll>(n));
    vector<pair<ll,ll> > ps;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        ps.emplace_back(x,y);
    }
    rep(i,n)rep(j,n){
        if(i==j) continue;
        D[i][j] = dist(ps[i].first,ps[i].second,ps[j].first,ps[j].second);
    }
    vector<bool> infected(n);
    infected[0] = false;
    queue<int> q;
    
    while(!q.empty()){
        
    }
    return 0;
}