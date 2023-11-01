#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,set<int> > > g(n);
    rep(i,n){
        int price;
        cin >> price;
        g[i].first = price;
        int c;
        cin >> c;
        vector<int> f(c);
        rep(j,c){
            cin >> f[j];
            g[i].second.insert(f[j]);
        }
    }
    bool ans = false;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(g[i].first <= g[j].first){
                int size = g[i].second.size();
                for(auto iter = g[j].second.begin(); iter != g[j].second.end();iter++){
                    if(!g[i].second.count(*iter)) break;
                    if(iter == g[j].second.end()){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}