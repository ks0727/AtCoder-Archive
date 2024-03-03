#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h1,w1;
    cin >> h1 >> w1;
    vector a(h1,vector<int>(w1));
    rep(i,h1)rep(j,w1) cin >> a[i][j];
    int h2,w2;
    cin >> h2 >> w2;
    vector b(h2,vector<int>(w2));
    rep(i,h2)rep(j,w2) cin >> b[i][j];
    int dh = h1-h2;
    int dw = w1-w2;
    auto combination = [&](vector<int> indexes, int r)->vector<vector<int> >{
        vector<vector<int> > res;
        int n = indexes.size();
        vector<int> now;
        auto dfs = [&](auto dfs, int v)->void{
            if(now.size() == r) {
                res.push_back(now);
                return;
            }
            if(v == n) return;
            //選ばない処理
            dfs(dfs,v+1);
            //選ぶ処理
            now.push_back(v);
            dfs(dfs,v+1);
            now.pop_back();
            return;
        };
        dfs(dfs,indexes[0]);
        return res;
    };
    vector<int> hidx,widx;
    rep(i,h1) hidx.push_back(i); 
    rep(i,w1) widx.push_back(i); 
    vector<vector<int> > delh = combination(hidx,h2);
    vector<vector<int> > delw = combination(widx,w2);
    for(auto arr1 : delh){
        for(auto arr2 : delw){
            vector<vector<int> > c;
            for(int ci : arr1){
                c.push_back({});
                for(int cj : arr2){
                    c.back().push_back(a[ci][cj]);
                }
            }
            bool done = false;
            rep(i,h2){
                if(done) break;
                rep(j,w2){
                    if(c[i][j] != b[i][j]){
                        done = true;
                        break;
                    }
                    if(i == h2-1 && j == w2-1){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}