#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

struct Edge{
    ll from,l,d,k,c;
    Edge(ll from,ll l, ll d,ll k,ll c):from(from),l(l),d(d),k(k),c(c){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int l,d,k,c,a,b;
        cin >> l >> d >> k >> c >> a >> b;
        a--; b--;
        g[b].emplace_back(a,l,d,k,c);
    }
    const ll INF = 8e18;
    vector<ll> f(n,-INF);
    f[n-1] = INF;
    priority_queue<P> q;
    q.emplace(INF,n-1);
    while(!q.empty()){
        auto [t,v] = q.top(); q.pop(); //tは暫定の最大値
        if(f[v] != t) continue; //queueに入っているのは最新情報になっていなかったらダメ
        for(auto e : g[v]){ //vから直接行ける駅について
            ll nt = t - e.c; //ntは出発しないといけない時間
            if(e.l > nt) continue; //出発しなきゃいけない時間がその駅の始発時刻よりも小さかったらだめ
            ll k = (nt-e.l)/e.d; //何本目の便が最適か
            k = min(k,e.k-1);
            ll nf = e.l+e.d*k; //暫定的な最大時間
            if(f[e.from] >= nf) continue;
            f[e.from] = nf; //暫定的な最大時間がfromからの時間よりも大きければ更新
            q.emplace(nf,e.from);
        }
    }
    rep(i,n-1){
        ll ans = f[i];
        if(ans == -INF) cout << "Unreachable" << '\n';
        else cout << ans << '\n';
    }
    return 0;
}