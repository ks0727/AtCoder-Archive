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
    vector<set<int> > change(n);
    set<pair<int,int> > st;
    vector<int> vtoe(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a,b);
        es.emplace_back(a,b,i);
        int en = max(ec[uf.leader(a)],ec[uf.leader(b)]);
        int add = 0;
        vtoe[a] = i;
        vtoe[b] = i;
        if(!uf.same(a,b)) add++;
        uf.merge(a,b);
        if(a == b){ //自己ループ
            change[uf.leader(a)].insert(i);
        }
        if(st.count(make_pair(a,b))){ //重複
            set<int> st1 = change[a];
            set<int> st2 = change[b];
            if(st1.size() > st2.size()) swap(st1,st2);
            for(int x : st1) st2.insert(x);
            change[uf.leader(a)] = st2;
        }else{
            st.emplace(a,b);
        }
        ec[uf.leader(a)] = en+1;
        vc[uf.leader(a)] += add;
    }

    int ans = uf.groups().size() - 1;
    cout << ans << endl;
    if(ans == 0) return 0;
    // rep(i,n){
    //     if(i != uf.leader(i)) continue;
    //     if(change[i].size() == 0) continue;
    //     cout << "------------------" << endl;
    //     cout << i << endl;
    //     for(int x : change[i]) cout << x << ' '; cout << endl;
    // }
    set<int> ls;
    rep(i,n) if(uf.leader(i) == i) ls.insert(i);
    vector<int> req;
    vector<T> ans_es;
    rep(i,n){
        if(uf.leader(i) != i) continue;
        int need = vc[uf.leader(i)]-1;
        int extra = ec[uf.leader(i)] - need; //余計な分
        if(extra == 0) req.push_back(i);
    }
    int used = 0;
    //rep(i,req.size()) cout << req[i] << ' '; cout << endl;
    rep(i,n){
        if(uf.leader(i) != i) continue;
        int need = vc[uf.leader(i)]-1;
        int extra = ec[uf.leader(i)] - need; //余計な分
        if(extra <= 0) continue;

        if(extra == 1){ //どれを使ってもOK
            int idx = vtoe[i];
            auto [a,b,idx2] = es[idx];
            if(req.size() != 0){
                ans_es.emplace_back(idx2+1,a+1,req.back()+1);
                uf.merge(a,req.back());
                used++;
                req.pop_back();
            }else{
                if(used == ans) break;
                int connect = -1;
                for(int x : ls){
                    if(x != i && !uf.same(x,i)){
                        ans_es.emplace_back(idx2+1,a+1,x+1);
                        connect = x;
                        uf.merge(i,x);
                        used++;
                        break;
                    }
                }
                if(connect != -1) ls.erase(connect);
            }
        }else{ //重複が2以上ある（もしくわ1つの頂点に自己ループが1つ以上存在）
            rep(j,extra){
                auto it = change[i].begin();
                auto [a,b,idx] = es[*it];
                if(req.size() != 0){
                    ans_es.emplace_back(*it,a+1,req.back()+1);
                    uf.merge(a,req.back());
                    req.pop_back();
                }else{
                    int connect = -1;
                    for(int x : ls){
                        if(x != i && !uf.same(x,i)){
                            ans_es.emplace_back(idx+1,a+1,x+1);
                            uf.merge(i,x);
                            connect = x;
                            used++;
                            break;
                        }
                    }
                    if(connect != -1) ls.erase(connect);
                }
                change[i].erase(it);
                if(used == ans) break;
            }
        }
        if(used == ans) break;
    }
    for(auto [idx,a,b] : ans_es) cout << idx+1 << ' ' << a << ' ' << b << endl;
    return 0;
}