#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n = 3;
    vector<vector<int> > a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    auto win = [&](vector<vector<int> > b){
        rep(ri,2){ //90°回転
            rep(i,n){
                bool ok = true;
                rep(j,n) if(b[i][j] != 1) ok = false;
                if(ok) return true;
            }
            if(b[0][0] == 1 && b[1][1] ==1 && b[2][2] == 1) return true;
            vector<vector<int> > old = b;
            rep(i,n)rep(j,n) b[i][j] = old[n-1-j][i];
        }
        return false;
    };
    auto f = [&](auto f,vector<vector<int> > b)->bool{
        bool end = true;
        rep(i,n)rep(j,n) if(b[i][j] == 0) end = false;
        if(end){
            ll s = 0;
            rep(i,n)rep(j,n) s+=a[i][j]*b[i][j];
            return s > 0;
        }
        rep(i,n)rep(j,n){
            if(b[i][j] == 0){
                vector<vector<int> > nb = b;
                nb[i][j] = 1;
                if(win(nb)) return true;
                rep(ni,n)rep(nj,n) nb[ni][nj] = -nb[ni][nj];
                if(!f(f,nb)) return true;
            }
        }
        return false;
    };
    if(f(f,vector<vector<int>>(3,vector<int>(3)))) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}