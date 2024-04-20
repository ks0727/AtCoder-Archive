#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<bool> exist(n,true);
    rep(qi,q){
        int t;
        cin >> t;
        t--;
        if(exist[t]) exist[t] = false;
        else exist[t] = true;
    }
    int ans = 0;
    rep(i,n){
        if(exist[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}