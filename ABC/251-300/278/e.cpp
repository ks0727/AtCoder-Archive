#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int> > a(H,vector<int>(W));
    rep(i,H)rep(j,W) cin >> a[i][j];
    map<int,set<P> > mp;
    rep(i,H){
        rep(j,W){
            mp[a[i][j]].insert(P(i,j));
        }
    }
    vector<vector<int> > ans(H-h+1,vector<int>(W-w+1,N));
    rep(k,H-h+1){
        rep(l,W-w+1){
            int now = mp.size();
            map<int,set<P> > nm = mp;
            for(int i=k;i<k+h;i++){
                for(int j=l;j<l+w;j++){
                    nm[a[i][j]].erase(P(i,j));
                    if(nm[a[i][j]].empty()) now--;
                }
            }
            ans[k][l] = now;
        }
    }
    rep(i,H-h+1){
        rep(j,W-w+1){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}