#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n,q;
    cin >> n >> q;
    vector<set<int> > g(n);
    rep(i,q){
        int input;
        cin >> input;
        if(input == 1){
            int a,b;
            cin >> a >> b;
            a--; b--;
            g[a].insert(b);
            g[b].insert(a);
            vector<bool> seen(n);
            queue<int> que;
            rep(i,n){
                if(g[i].empty()) continue;
                que.push(i);
                while(!que.empty()){
                    int value = que.front();
                    que.pop();
                    for(auto u : g[value]){
                        if(seen[u]) continue;
                        seen[u] = true;
                        que.push(u);
                    }
                }
            }
            int ans = 0;
            rep(i,n) if(!seen[i]) ans++;
            cout << ans << endl;
        }
        if(input == 2){
            int value;
            cin >> value;
            value--;
            rep(i,n){
                if(g[i].count(value)) g[i].erase(value);
            }
            g[value].clear();
            queue<int> que;
            vector<bool> seen(n);
            rep(i,n){
                if(g[i].empty()) continue;
                que.push(i);
                while(!que.empty()){
                    int value = que.front();
                    que.pop();
                    for(auto u : g[value]){
                        if(seen[u]) continue;
                        seen[u] = true;
                        que.push(u);
                    }
                }
            }
            int ans = 0;
            rep(i,n) if(!seen[i]) ans++;
            cout << ans << endl;
        }
    }
    return 0;
}