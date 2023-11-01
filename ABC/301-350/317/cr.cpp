#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Edge{
    int next;
    int cost;
    Edge() : next(-1),cost(-1){}
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        Edge e1,e2;
        e1.next = b; e2.next = a;
        e1.cost = c; e2.cost = c;
        g[a].push_back(e1);
        g[b].push_back(e2);
    }
    int ans = -1;
    rep(i,n){
        vector<bool> visited(n);
        stack<int> q;
        q.push(i);
        visited[i] = true;
        int current = 0;
        while(!q.empty()){
            int v = q.top();
            q.pop();
            for(auto u : g[v]){
                if(visited[u.next]) continue;
                q.push(u.next);
                visited[u.next] = true;
                current += u.cost;
            }
            ans = max(ans,current);
        }
        visited = vector<bool>(n,false);
    }
    cout << ans << endl;
    return 0;
}