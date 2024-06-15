#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;

    vector<bool> used(n); //usedは本当に終了している
    vector<int> idx(n,-1); 
    vector<int> ord;
    vector<int> cnt(n);
    rep(sv,n){
        if(used[sv]) continue;
        int v = sv;
        vector<int> vs;
        while(1){
            if(used[v]) break;
            if(idx[v] != -1){ //サイクルが見つかった！
                vector<int> cyc(vs.begin()+idx[v],vs.end());
                for(int u : cyc){ //サイクル内の頂点の訪れることのできる頂点数はサイクル内頂点の数
                    cnt[u] = cyc.size();
                    break;
                }
            }
            idx[v] = vs.size();
            vs.push_back(v);
            v = a[v];
        }
        for(int v : vs) used[v] = true;
        reverse(vs.begin(),vs.end());
        ord.insert(ord.end(),vs.begin(),vs.end());
    }
    for(int v : ord){
        if(cnt[v] != 0 ) continue;
        cnt[v] = cnt[a[v]] +1;
    }
    ll ans = 0;
    rep(i,n) ans += cnt[i];
    cout << ans << endl; 
    return 0;
}