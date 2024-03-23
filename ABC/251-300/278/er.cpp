#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Pos{
    int l,r,u,d;
    Pos(int l=301,int r=0,int u=301,int d=0):l(l),r(r),u(u),d(d){}
};
void chmin(int &a, int &b){a = min(a,b);}
void chmax(int &a, int &b){a = max(a,b);}
int main(){
    int H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int> > a(H,vector<int>(W));
    rep(i,H)rep(j,W) cin >> a[i][j];
    vector<Pos> ns(N);
    rep(i,H)rep(j,W){
        int num = a[i][j];
        num--;
        chmin(ns[num].l,j);
        chmax(ns[num].r,j);
        chmin(ns[num].u,i);
        chmax(ns[num].d,i);
    }
    rep(k,H-h+1){
        rep(l,W-w+1){
            int cu = k, cd = k+h-1,cl = l, cr=l+w-1;
            int now = 0;
            rep(i,N){
                if(ns[i].l < cl) continue;
                if(ns[i].r > cr) continue;
                if(ns[i].u < cu) continue;
                if(ns[i].d > cd) continue;
                now++;
            }
            cout << N - now << ' ';
        }
        cout << '\n';
    }
    return 0;
}