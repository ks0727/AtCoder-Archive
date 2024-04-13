#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int main(){
    vector<ll> a(9);
    rep(i,9) cin >> a[i];
    const ll INF = 1e18;
    vector<vector<int> > check =   {{0,1,2},
                                    {3,4,5},
                                    {6,7,8},
                                    {0,3,6},
                                    {1,4,7},
                                    {2,5,8},
                                    {0,4,8},
                                    {2,4,6}};

    auto dfs = [&](auto dfs,int now, vector<int> s)->ll{
        for(auto l : check){
            if(s[l[0]] == s[l[1]] && s[l[1]] == s[l[2]] && s[l[0]] == 1){
                return INF;
            }
            if(s[l[0]] == s[l[1]] && s[l[1]] == s[l[2]] && s[l[0]] == -1){
                return -INF;
            }
        }
        if(now == 9){
            ll s1 = 0,s2 = 0;
            rep(i,9){
                if(s[i] == 1) s1 += a[i];
                else s2 += a[i];
            }
            return s1-s2;
        }
        if(now%2 == 0){ // Takahashi's turn
            ll tmp = -INF;
            rep(i,9){
                if(s[i] == 0){
                    auto t = s;
                    t[i] = 1;
                    tmp = max(tmp,dfs(dfs,now+1,t));
                }
            }
            return tmp;
        }else{ // Aoki's turn
            ll tmp = INF;
            rep(i,9){
                if(s[i] == 0){
                    auto t = s;
                    t[i] = -1;
                    tmp = min(tmp,dfs(dfs,now+1,t));
                }
            }
            return tmp;
        }
    };
    if(dfs(dfs,0,vector<int>(9))>=0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0; 
}