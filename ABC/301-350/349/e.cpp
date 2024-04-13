#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int main(){
    vector<int> a(9);
    rep(i,9) cin >> a[i];
    vector<int> put(9);
    const ll INF = 1e18;
    vector<vector<int> > check = 
    {{0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
    };
    auto dfs = [&](auto dfs,int now)->ll{
        for(auto l : check){
            if(put[l[0]] == put[l[1]] && put[l[1]] == put[l[2]] && put[l[0]] == 1){
                return INF;
            }
            if(put[l[0]] == put[l[1]] && put[l[1]] == put[l[2]] && put[l[0]] == -1){
                return -INF;
            }
        }
        if(now == 9){
            ll res = 0;
            rep(i,9){
                if(put[i] == 1) res += a[i]; 
                else res -= a[i];
            }
            return res; //scoreはtakahashi-aokiの点数とする
        } 
        if(now%2 == 0){ //takahashiのターンの時
            ll tmp = -INF;
            rep(i,9){
                if(put[i] == 0){
                    put[i] = 1;
                    tmp = max(tmp,dfs(dfs,now+1)); //現時点で置かれていないマスに置いた際に得られる最大値
                    put[i] = 0;
                } 
            }
            return tmp;
        }else{
            ll tmp = INF;
            rep(i,9){
                if(put[i] == 0){
                    put[i] = -1;
                    tmp = min(tmp,dfs(dfs,now+1)); //現時点で置かれていないマス置いた際に得られる最小値
                    put[i] = 0;
                }
            }
            return tmp;
        }
    };
    if(dfs(dfs,0) >= 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}