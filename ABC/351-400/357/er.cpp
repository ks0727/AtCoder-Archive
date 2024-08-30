#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;
    vector<int> ans(n),visited(n),dim(n);
    rep(i,n) dim[a[i]]++;
    vector<bool> seen(n);

    rep(i,n){
        if(seen[i]) continue;
        int v = i;
        vector<int> visited;
        while(!seen[v]){
            seen[v] = true;
            visited.push_back(v);
            v = a[v];
        }
        if(ans[v] != 0){
            int now = ans[v];
            while(visited.size() > 0){
                ans[visited.back()] = ++now;
                visited.pop_back();
            }
            continue;
        }else{ //サイクルが存在
            int u = v;
            int cs = 0;
            do{
                cs++;
                u = a[u];
            }while(u != v);
            rep(i,cs){ //サイクル上の答え
                ans[visited.back()] = cs;
                visited.pop_back();
            }
            reverse(visited.begin(),visited.end());
            int cnt = 0;
            for(int x : visited) ans[x] = ++cnt + cs;
        }
    }
    ll k = 0;
    rep(i,n) k += ans[i];
    cout << k << endl;
    return 0;
}