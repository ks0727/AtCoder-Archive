#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int pow(int a, int b){
    int res = 1;
    rep(i,b) res *= a;
    return res;
}

int main(){
    int n;
    cin >> n;
    auto f = [&](auto f, int x)->vector<string>{
        if(x == 0) return {"#"};
        int sz = pow(3,x);
        vector<string> res(sz,string(sz,'.'));
        vector<string> tile = f(f,x-1);
        rep(i,3){
            rep(j,3){
                if(i == 1 && j == 1) continue;
                rep(ii,sz/3){
                    rep(jj,sz/3){
                        res[i*sz/3+ii][j*sz/3+jj] = tile[ii][jj];
                    }
                }
            }
        }
        return res;
    };
    vector<string> ans = f(f,n);
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}