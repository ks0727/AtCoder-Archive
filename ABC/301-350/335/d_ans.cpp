#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > ans(n,vector<int>(n,-1));

    int num = 1;
    int i = 0,j = 0;
    auto f = [&](int di,int dj){
        ans[i][j] = num;
        num++;
        i += di; j += dj;
    };

    for(int l = n-1;l>0;l-=2){
        rep(k,l) f(0,1);
        rep(k,l) f(1,0);
        rep(k,l) f(0,-1);
        rep(k,l-1) f(-1,0);
        f(0,1);
    }

    rep(i,n){
        rep(j,n){
            if(ans[i][j] == -1) cout << 'T';
            else cout << ans[i][j];
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}