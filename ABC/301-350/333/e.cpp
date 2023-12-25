#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    const int INF = 1e9;
    int ans = INF;
    int now = -INF;
    auto dfs = [&](auto dfs, vector<int> p, int k)->void{
        int t;
        cin >> t;
        now = max(k,now);
        if(t == 1){
            int x;
            cin >> x;
            dfs(dfs,p,k);
            p[x]++;
            dfs(dfs,p,k+1);
        }else if(t == 2){
            int x;
            cin >> x;
            x--;
            p[x]--;
            k--;
            dfs(dfs,p,k);
        }
    };
    dfs(dfs,vector<int>(n),0);
}