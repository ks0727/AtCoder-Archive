#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<int> > cnt(10,vector<int>(10));
    rep(i,n){
        rep(j,10) cnt[s[i][j]-'0'][j]++;
    }
    int ans = 1001001001;
    rep(i,10){ //ある数 i 
        int mx = 0;
        int nj = -1;
        rep(j,10){ //その場所に何個ある？
            if(mx <= cnt[i][j]){
                mx = cnt[i][j];
                nj = j;
            }
        }
        //cout << i << ' ' << mx << ' ' << nj << endl;
        ans = min(ans,10*(mx-1)+nj);
    }
    cout << ans << endl;
    return 0;
}