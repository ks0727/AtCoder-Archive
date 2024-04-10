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
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    rep(a,n){
        for(int b=a+1;b<n;b++){
            for(int c=b+1;c<n;c++){
                if(!g[a].count(b)) continue;
                if(!g[b].count(c)) continue;
                if(!g[a].count(c)) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}