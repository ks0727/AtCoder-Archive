#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    deque<int> dx,dy;
    rep(i,n){
        int a;
        cin >> a;
        if(i%2 == 0){
            dx.push_back(a);
        }else{
            dy.push_back(a);
        }
    }
    auto f = [&](deque<int> d, int target, char now)->bool{
        bool minus = false; //最終的な座標が負か？
        if(target < 0){
            target *= -1;
            minus = true;
        }
        int diff = (10*((n+1)/2)-target+1)/2;
        if(diff < 0) return false;
        vector<vector<bool> > dp(n+5,vector<bool>(10005));
        if(now == 'y'){
            dp[0][diff] = true;
        }else{
            if(minus) dp[0][diff-d[0]] = true;
            else dp[0][diff+d[0]] = true;
            d.pop_front();
        }
        for(int i=1;i<=d.size();i++){
            rep(j,10005){
                if(j+d[i-1] >= 0 && j+d[i-1] < 10005) if(dp[i-1][j+d[i-1]]){
                    if(j < 10005) dp[i][j] = true;
                } 
                if(j-d[i-1] >= 0 && j-d[i-1] < 10005) if(dp[i-1][j-d[i-1]]){
                    if(j < 10005) dp[i][j] = true;
                } 
            }
        }
        return dp[int(d.size())][target+diff];
    };
    if(f(dx,x,'x') && f(dy,y,'y')) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}