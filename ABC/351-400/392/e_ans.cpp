#include <bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using T = tuple<int,int,int>;
int main(){
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    vector<T> es;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(uf.same(a,b)){ //この辺は余分な辺
            es.emplace_back(i,a,b);
        }else{
            uf.merge(a,b);
        }
    }
    set<int> leaders;
    rep(i,n) leaders.insert(uf.leader(i));
    cout << leaders.size() - 1 << endl; //付け替える必要のある辺の本数
    while(leaders.size() > 1){ //連結成分数が1になるまで繰り返す
        auto [ei,a,b] = es.back();
        es.pop_back();
        int v = uf.leader(a); //aのleader
        leaders.erase(v);

        int u = *leaders.begin();
        leaders.erase(u);

        uf.merge(u,v);
        leaders.insert(uf.leader(v));

        printf("%d %d %d\n",ei+1,a+1,u+1);
    }
    return 0;
}