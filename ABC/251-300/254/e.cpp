#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(mi,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;

    while(q--){
        int x,k;
        cin >> x >> k;
        x--;
        ll now = 0;
        vector<int> visited(n,-1);
        queue<int> q;
        q.push(x);
        visited[x] = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            now += v+1;
            if(visited[v] == k) continue;;
            for(int u : g[v]){
                if(visited[u] != -1) continue;
                q.push(u);
                visited[u] = visited[v] + 1;
            }
        }
        cout << now << '\n';
    }
    return 0;
}