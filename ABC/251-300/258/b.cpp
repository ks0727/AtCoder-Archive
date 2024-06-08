#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const int di[] = {1,1,1,0,0,-1,-1,-1};
const int dj[] = {-1,0,1,1,-1,1,-1,0};
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<ll> > a(n,vector<ll>(n));
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n)rep(j,n) a[i][j] = s[i][j]-'0';
    ll ans = -1;
    rep(i,n)rep(j,n){
        int y = i,x = j;
        rep(d,8){
            ll now = 0;
            rep(k,n){
                int ny = (y+di[d]+n)%n;
                int nx = (x+dj[d]+n)%n;
                now = now*10 + a[ny][nx];
                x = nx; y = ny;
            }
            ans = max(ans,now);
        }
    } 
    cout << ans << endl;
    return 0;
}