#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    auto comb = [&](int n, int m)->vector<vector<int> >{
        vector<vector<int> > res;
        vector<int> seen;
        auto dfs = [&](auto dfs, int v)->void{
            if(seen.size() == n){
                res.push_back(seen);
                return;
            }
            if(v == m+1) return;
            dfs(dfs,v+1);
            seen.push_back(v);
            dfs(dfs,v+1);
            seen.pop_back();
        };
        dfs(dfs,1);
        return res;
    };
    vector<vector<int> > ans = comb(n,m);
    reverse(ans.begin(),ans.end());
    for(auto v : ans){
        rep(i,v.size()) cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}