#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w,si,sj;
    cin >> h >> w >> si >> sj;
    si--; sj--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    string t;
    cin >> t;
    vector<vector<bool> > visited(h,vector<bool>(w));
    visited[si][sj] = true;
    int ci = si; int cj = sj;
    map<char,int> mp;
    mp['U'] = 0;
    mp['D'] = 1;
    mp['L'] = 2;
    mp['R'] = 3;
    int di[] = {-1,1,0,0};
    int dj[] = {0,0,-1,1};
    rep(k,t.size()){
        char c = t[k];
        int ni = ci + di[mp[c]];
        int nj = cj + dj[mp[c]];
        if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if(s[ni][nj] == '#') continue;
        visited[ni][nj] = true;
        ci = ni; cj = nj;
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '@' && visited[i][j]) ans++;
    }
    cout << ci+1 << ' ' << cj+1 <<  ' ' << ans << endl;
    return 0;
}