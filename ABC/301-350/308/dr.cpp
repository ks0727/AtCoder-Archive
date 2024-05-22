#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    string snuke = "snuke";
    map<char,char> mp;
    rep(i,5) mp[snuke[i]] = snuke[(i+1)%5];
    queue<P> q;
    if(s[0][0] != 's'){
        cout << "No" << endl;
        return 0; 
    }
    q.emplace(0,0);
    vector<vector<bool> > visited(h,vector<bool>(w));
    visited[0][0] = true;
    while (!q.empty()){
        auto [i,j] = q.front(); q.pop();
        char target = mp[s[i][j]];
        rep(d,4){
            int ni = i+di[d]; int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(visited[ni][nj]) continue;
            if(s[ni][nj] != target) continue;
            visited[ni][nj] = true;
            q.emplace(ni,nj);
        }
    }
    if(visited[h-1][w-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}