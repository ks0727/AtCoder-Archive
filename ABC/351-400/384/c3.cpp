#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> x(5);
    vector<pair<int,string> > ps;
    rep(i,5) cin >> x[i];
    auto dfs = [&](auto dfs, vector<int> a, int d = 0){
        if(d == 5){
            if(a.size() == 0) return;
            int now = 0;
            string t = "";
            rep(i,a.size()){
                now += x[a[i]];
                t += char('A'+a[i]);
            }
            ps.emplace_back(-now,t);
            return;
        }
        dfs(dfs,a,d+1);
        vector<int> na = a;
        na.push_back(d);
        dfs(dfs,na,d+1);
    };
    dfs(dfs,vector<int>(0));
    sort(ps.begin(),ps.end());
    rep(i,31){
        cout << ps[i].second << endl;
    }
    return 0;
}