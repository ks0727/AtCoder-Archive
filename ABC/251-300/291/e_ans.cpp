#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<int> deg(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a; --b;
        g[b].push_back(a);
        deg[a]++;
    }
    queue<int> q;
    rep(i,n){
        if(deg[i] == 0) q.push(i);
    }
    vector<int> A(n); int na = n;
    while(!q.empty()){
        if(q.size() > 1){
            cout << "No" << endl;
            return 0;
        }
        int v = q.front(); q.pop();
        A[v] = na; na--;
        for(int u : g[v]){
            deg[u]--;
            if(deg[u] == 0) q.push(u);
        }
    }
    cout << "Yes" << endl;
    rep(i,n) cout << A[i] << endl;
    cout << endl;
    return 0;
}