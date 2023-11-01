#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> > a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    set<int> s;
    int ans = 0;
    auto dfs = [&](auto f,int i, int j) -> void{
        if(i >= h || j >= w) return;
        if(s.count(a[i][j])) return;
        if(i == h-1 && j == w-1){
            ans++;
            return;
        }
        s.insert(a[i][j]);
        cout << endl;
        f(f,i,j+1);
        f(f,i+1,j);
        s.erase(a[i][j]);
    };
    dfs(dfs,0,0);
    cout << ans << endl;
    return 0;
}