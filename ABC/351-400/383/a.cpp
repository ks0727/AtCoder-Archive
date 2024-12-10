#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > ps;
    rep(i,n){
        int t,v;
        cin >> t >> v;
        ps.emplace_back(t,v);
    }
    int ans = 0;
    int id = 0;
    for(int t=1;t<=100;t++){
        if(id < n && ps[id].first == t){
            ans += ps[id].second;
            id++;
            if(id == n) break;
        }
        if(ans >= 1) ans--;
        //cout << t << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}