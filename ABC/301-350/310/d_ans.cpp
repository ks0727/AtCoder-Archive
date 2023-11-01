#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,t,m;
    cin >> n >> t >> m;
    vector<vector<bool> > bad(n,vector<bool>(n));

    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        bad[a][b] = true;
        bad[b][a] = true;
    }
    int ans = 0;
    vector<vector<int> > team;
    auto f = [&](auto f, int i) ->  void{
        if(i == n){
            if(team.size() == t) ans++;
            return;
        }
        //既存のチームにいれる
        rep(j,team.size()){
            bool ok = true;
            for(int p:team[i]){
                if(bad[i][p]) ok = false;
            }
            if(!ok) continue;
            team[j].push_back(i);
            f(f,i+1);
            team.pop_back();
        }
        //新しいチームを作る
        team.push_back(vector<int>(1,i));
        f(f,i+1);
        team.pop_back();
    };
    f(f,0);
    cout << ans << endl;
    return 0;
}