#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> xs;
    auto dfs = [&](auto dfs, int d, vector<vector<int> > groups){
        if(d == n){
            ll x = 0;
            rep(j,groups.size()){
                ll sum = 0;
                for(int nv : groups[j]){
                    sum += a[nv];
                }
                x ^= sum;
            }
            xs.push_back(x);
            return;
        }
        //すでにあるグループにいれる
        rep(j,groups.size()){
            groups[j].push_back(d);
            dfs(dfs,d+1,groups);
            groups[j].pop_back();
        }
        //新しいグループを作成する
        groups.push_back(vector<int>(1,d));
        dfs(dfs,d+1,groups);
    };
    dfs(dfs,0,{});
    sort(xs.begin(),xs.end()); 
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    cout << xs.size() << endl;
    return 0;
}