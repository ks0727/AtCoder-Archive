#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace atcoder;
using T = tuple<int,int,int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<T> es;
    dsu uf(n);
    vector<int> ec(n);
    vector<int> vc(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a,b);
        es.emplace_back(a,b,i);
        int en = max(ec[uf.leader(a)],ec[uf.leader(b)]);
        int add = 0;
        if(!uf.same(a,b)) add++;
        uf.merge(a,b);
        ec[uf.leader(a)] = en+1;
        vc[uf.leader(a)] += add;
    }
    int ans = uf.groups().size() -1;
    cout << ans << endl;
    if(ans == 0) return 0;
    //各連結成分同士を繋ぐパート
    set<pair<int,int> > st;
    vector<vector<int> > extras(n);

    rep(i,m){//ここでは自己ループ, 重複辺がどの連結成分にあるかどうかを求める
        auto [a,b,idx] = es[i];
        if(st.count(make_pair(a,b))){ //重複
            extras[uf.leader(a)].push_back(idx);
            continue;
        }else{
            st.emplace(a,b);
            continue;
        }
        if(a == b){
            extras[uf.leader(a)].push_back(idx);
        }
    }
    set<int> res,plus;
    vector<T> ans_es;
    rep(i,n){
        if(i == uf.leader(i) && extras[i].size() == 0) res.insert(i);
        else if(i == uf.leader(i) && extras[i].size() >= 1) plus.insert(i);
    }
    rep(i,n){
        if(res.size() == 0) break;
        if(plus.count(i)){
            for(int x : extras[i]){
                auto [a,b,c] = es[x];
                ans_es.emplace_back(c+1,i+1,*res.begin());
                res.erase(res.begin());
                if(res.size() == 0) break;
            }
        }
    }
    
}