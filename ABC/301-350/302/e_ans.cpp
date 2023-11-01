#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<unordered_set<int> > to(n);
    int ans = n;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int a,b;
            cin >> a >> b;
            a--;b--;
            if(to[a].size() == 0) ans--;
            if(to[b].size() == 0) ans--;
            to[a].insert(b);
            to[b].insert(a);
        }else{
            int v;
            cin >> v;
            v--;
            if(to[v].size()){
                for(auto u : to[v]){
                    to[u].erase(v);
                    if(to[u].size() == 0) ans++;
                }
                to[v].clear();
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}