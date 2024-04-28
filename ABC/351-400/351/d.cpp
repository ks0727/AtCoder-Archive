#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<bool> > adj(h,vector<bool>(w));
    //上下左右いずれかが磁石であるマスを記録しておく
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            rep(d,4){
                int ni = i+di[d]; int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(s[ni][nj] == '#'){
                    adj[i][j] = true;
                    break;
                }
            }
        }
    }
    vector<vector<bool> > visited(h,vector<bool>(w));
    auto dfs = [&](auto dfs,P pos,set<P> st)->int{
        int res = 1;
        auto [i,j] = pos;
        if(adj[i][j]){
            visited[i][j] = true;
            st.insert(P(i,j));
            return res;
        } 
        visited[i][j] = true;
        rep(d,4){
            int ni = i+di[d]; int nj = j+dj[d];
            if(visited[ni][nj]) continue;
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(s[ni][nj] == '#') continue;
            res += dfs(dfs,P(ni,nj),st);
            //visited[ni][nj] = false;
        }
        return res;
    };
    int ans = -1;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            if(visited[i][j]) continue;
            set<P> st;
            ans = max(ans,dfs(dfs,P(i,j),st));
            for(auto [si,sj] : st) visited[si][sj] = false;
        }
    }
    cout << ans << endl;
    return 0;
}