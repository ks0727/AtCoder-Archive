#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    rep(i,n) cin >> a[i];
    for(int i=1;i<(n);i++) cin >> p[i];
    vector<vector<int> > g(n);
    rep(i,n-1){
        g[p[i]-1].push_back(i+1);
    }
    ll sum = 0;
    auto dfs = [&](auto dfs, int v)->void{
        for(auto u : g[v]){
            dfs(dfs,u);
        }
        if(v == n-1) return;
        sum += a[v+1];
    };
    dfs(dfs,0);
    if(sum > 0){
        cout << '+' << endl;
        return 0;
    }else if(sum < 0){
        cout << '-' << endl;
        return 0;
    }else{
        if(a[0] > 0){
            cout << '+' << endl;
            return 0;
        }else if(a[0] < 0){
            cout << '-' << endl;
            return 0;
        }else{
            cout << 0 << endl;
            return 0;
        }
    }
    return 0;
}