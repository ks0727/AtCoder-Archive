#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

void chmax(int &a, int b){a = max(a,b);}

int main(){
    int n;
    cin >> n;
    const int INF = 1e9;
    const int L = 2<<17;
    vector<int> dp(L+400,-INF);
    dp[0] = 0;
    rep(i,n){
        int l,r,p;
        cin >> l >> r >> p;
        rep(j,L+1){
            int njl = j + l; 
            int njr = j + r;
            //chmax(dp[njl],dp[njl]);
            chmax(dp[njl],dp[j]+p);
            //chmax(dp[njr],dp[njr]);
            chmax(dp[njr],dp[j]+p);
        }
    }
    int m;
    cin >> m;
    vector<int> ans;
    rep(mi,m){
        int w;
        cin >> w;
        if(dp[w] == -INF){
            cout << -1 << endl;
            return 0;
        } 
        else ans.push_back(dp[w]);
    }
    for(int x : ans) cout << x << '\n';
    return 0;
}