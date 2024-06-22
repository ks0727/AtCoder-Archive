#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    vector<int> cnt(n);
    dsu uf(n);
    rep(i,n){
        int c;
        cin >> c;
        rep(ci,c){
            int p;
            cin >> p;
            p--;
            g[p].push_back(i);
            cnt[i]++;
            uf.merge(p,i);
        }
    }
    queue<int> q;
    rep(i,n) if(cnt[i] == 0 && uf.same(i,0)) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int v = q.front(); q.pop();
        ans.push_back(v);
        for(auto u : g[v]){
            cnt[u]--;
            if(cnt[u] == 0) q.push(u);
        }
    }
    ans.pop_back();
    for(auto x : ans) cout << x+1<<' '; cout << endl;
    return 0;
}