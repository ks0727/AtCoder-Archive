#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> ub(n);
    for(int i=n-1;i>=0;i--) ub[i] = m-10*(n-i-1);
    vector<vector<int> > ans;
    vector<int> visit;
    auto dfs = [&](auto dfs,int d, int prev)->void{
        if(d == n){
            ans.push_back(visit);
            return;
        }
        for(int i=prev+10;i<=ub[d];i++){
            visit.push_back(i);
            dfs(dfs,d+1,i);
            visit.pop_back();
        }
    };
    dfs(dfs,0,-9);
    cout << ans.size() << endl;
    rep(i,ans.size()){
        rep(j,n) cout << ans[i][j] << ' '; cout << endl;
    }
    return 0;
}