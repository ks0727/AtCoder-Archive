#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > ss(m);
    rep(i,m){
        int c;
        cin >> c;
        rep(j,c){
            int a;
            cin >> a;
            ss[i].push_back(a);
        }
    }
    int ans = 0;
    for(int bit = 0;bit<(1<<m);bit++){
        vector<bool> seen(n);
        rep(i,m){
            if(bit & (1<<i)){
                rep(j,ss[i].size()){
                    int v = ss[i][j];
                    v--;
                    seen[v] = true;
                }
            }
        }
        rep(i,n){
            if(!seen[i]) break;
            if(i == n-1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}