#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    dsu uf(n);
    vector<P> ps;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        ps.emplace_back(x,y);
    }
    auto f = [&](P p1, P p2)->bool{
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i == 0 && j == 0) continue;
                if(i == -1 && j == 1) continue;
                if(i == 1 && j == -1) continue;
                if(p1.first == p2.first+i && p1.second == p2.second+j) return true;
            }
        }
        return false;
    };
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(uf.same(i,j)) continue;
            if(f(ps[i],ps[j])) uf.merge(i,j);
        }
    }
    set<int> st;
    rep(i,n){
        st.insert(uf.leader(i));
    }
    cout << st.size() << endl;
    return 0;
}
