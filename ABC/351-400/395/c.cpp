#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    const int M = 1e6+5;
    vector<vector<int> > pos(M);
    rep(i,n){
        int a;
        cin >> a;
        pos[a].push_back(i);
    }
    const int INF = 1e9;
    int ans = INF;
    rep(i,M){
        if(pos[i].size() < 2) continue;
        rep(j,pos[i].size()-1){
            ans = min(pos[i][j+1]-pos[i][j]+1,ans);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}