#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > to(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    ll tot = 0;
    rep(i,n) tot += c[i];
    int x = -1; //xは重心
    {
        auto dfs = [&](auto dfs,int v, int p=-1)->ll{ //重心xを求める
            ll res = c[v]; //とりあえずの今注目している頂点の部分木サイズ
            ll mx = 0;
            for(int u : to[v]){
                if(u == p) continue;
                ll now = dfs(dfs,u,v); //小要素の部分木サイズ
                mx = max(now,mx); //小要素の中での最大部分木サイズが入る
                res += now; //注目している頂点の部分木サイズは小要素部分木サイズの和になる
            }
            mx = max(mx,tot-res); //小要素の部分木サイズの最大値と,全体からvの部分木サイズを引いた値の大きい方が入る
            if(mx*2 <= tot) x = v;
            return res;
        };
        dfs(dfs,0);
    }
    ll ans = 0;
    auto dfs = [&](auto dfs,int v,int dist=0,int p=-1)->void{ //重心からの距離とc[i]をもとに最終的な答えf(x)を計算
        ans += (ll)dist*c[v];
        for(int u : to[v]){
            if(u == p) continue;
            dfs(dfs,u,dist+1,v);
        }
    };
    dfs(dfs,x);
    cout << ans << endl;
    return 0;
}