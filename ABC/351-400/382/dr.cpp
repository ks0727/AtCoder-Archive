#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> visit;
    vector<vector<int> > ans;
    auto dfs = [&](auto dfs)->void{
        if(visit.size() == n){
            ans.push_back(visit);
            return;
        }
        int start = visit.size()==0 ? 1 : visit.back()+10;
        int limit = m - 10*(n-visit.size()-1);
        for(int i=start;i<=limit;i++){
                visit.push_back(i);
                dfs(dfs);
                visit.pop_back();
        }
    };
    dfs(dfs);
    cout << ans.size() << endl;
    for(auto arr : ans){
        for(int x : arr) cout << x << ' '; cout << endl;
    }
    return 0;
}