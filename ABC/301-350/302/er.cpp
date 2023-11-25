#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<set<int> > g(n);
    set<int> connected;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int a,b;
            cin >> a >> b;
            a--; b--;
            g[a].insert(b);
            g[b].insert(a);
            connected.insert(a);
            connected.insert(b);
        }
        if(type == 2){
            int a;
            cin >> a;
            a--;
            for(auto u : g[a]){
                g[u].erase(a);
                if(g[u].size() == 0) connected.erase(u);
            }
            g[a].clear();
            connected.erase(a);
        }
        cout << n - connected.size() << endl;
    }
    return 0;
}