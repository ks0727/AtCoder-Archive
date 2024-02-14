#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll r = 1e16, l = -1;
    while(r-l>1){
        ll m = (r+l)/2;
        auto f = [&](ll x){
            vector<ll> s(n);
            vector<bool> del(n);
            queue<int> q;
            rep(i,n){
                for(int j:g[i]) s[i] += a[j]; //s[i]はi番目の頂点に隣接する頂点のコストの和
                if(s[i] <= x){ //i番目の頂点を削除するのに必要なコストがx以下ならば削除する
                    del[i] = true;
                    q.push(i);
                }
            }
            int cnt = 0;
            while(!q.empty()){
                int v = q.front(); q.pop(); 
                cnt++;
                for(int u : g[v]){
                    s[u] -= a[v]; //uを削除
                    if(!del[u] && s[u] <= x){
                        del[u] = true;
                        q.push(u);
                    }
                }
            }
            return cnt == n;
        };
        if(f(m)) r = m; else l = m;
    }
    cout << r << endl;
    return 0;
}