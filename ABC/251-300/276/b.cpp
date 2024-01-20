#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<set<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    rep(i,n){
        cout << g[i].size() << ' ';
        for(int x : g[i]){
            cout << x + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}