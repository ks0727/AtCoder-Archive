#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using T = tuple<ll,int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
int main(){
    int h,w; ll x;
    cin >> h >> w >> x;
    int si,sj;
    cin >> si >> sj;
    si--; sj--;
    vector<vector<ll> > s(h,vector<ll>(w));
    rep(i,h)rep(j,w) cin >> s[i][j];
    ll now = s[si][sj];
    priority_queue<T,vector<T>,greater<T> > q;
    q.emplace(s[si][sj],si,sj);
    vector<vector<bool> > seen(h,vector<bool>(w));
    vector<vector<bool> > bombed(h,vector<bool>(w));
    seen[si][sj] = true;
    bombed[si][sj] = true;
    while(!q.empty()){
        auto [c,i,j] = q.top(); q.pop();
        bool canb = false;
        rep(d,4){
            int ni = i+di[d];
            int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(bombed[ni][nj]) canb = true;
        }
        if((now+x-1)/x > s[i][j] && canb){
            now += c;
            bombed[i][j] = true;
        }
        rep(d,4){
            int ni = i+di[d];
            int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(seen[ni][nj]) continue;
            q.emplace(s[ni][nj],ni,nj);
            seen[ni][nj] = true;
        }
    }
    cout << now << endl;
    return 0;
}