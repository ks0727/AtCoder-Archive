#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>; 

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> es;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        es.push_back(P(a,b));
    }
    dsu uf(n);
    for(auto [a,b] : es){
        uf.merge(a,b);
    }
    vector<int> numV(n),numE(n);
    rep(v,n) numV[uf.leader(v)]++;
    for(auto[a,b] : es){
        numE[uf.leader(a)]++;
    }
    rep(i,n){
        if(numV[i]){
            if(numV[i] != numE[i]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}