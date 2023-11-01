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
    int uni = 0;
    vector<bool> seen(n);
    rep(i,n){
        queue<int> q;
        if(!seen[i]){
            q.push(i);
            seen[i] = true;
            uni++;
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u : g[v]){
                if(seen[u]) continue;
                q.push(u);
                seen[u] = true;
            }
        }
    }
    cout << m - n + uni << endl;
    return 0;
}