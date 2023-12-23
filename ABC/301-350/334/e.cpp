#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using mint = modint998244353;

const int di[] = {1,0,-1,0}; 
const int dj[] = {0,1,0,-1}; 

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int green = 0;
    P in = P(0,0);
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                green++;
            }
        }
    }
    vector<vector<bool> > visited(h,vector<bool>(w));
    map<P,int> mp;
    auto dfs = [&](auto dfs,P pos,int c)->void{
        auto [i,j] = pos;
        visited[i][j] = true;
        mp[P(i,j)] = c;
        rep(d,4){
            int ni = i+di[d];
            int nj = j+dj[d];
            if(ni < 0 || nj < 0 || ni > h-1 || nj > w-1) continue;
            if(visited[ni][nj]) continue;
            if(s[ni][nj] == '.') continue;
            dfs(dfs,P(ni,nj),c);
        }
    };
    int c = 0;
    rep(i,h){
        rep(j,w){
            if(!visited[i][j] && s[i][j] == '#'){
                dfs(dfs,P(i,j),c);
                c++;
            } 
        }
    }
    int red = h*w - green;
    mint ans = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            set<int> cons;
            rep(d,4){
                int ni = i+di[d];
                int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni > h-1 || nj > w-1) continue;
                if(s[ni][nj] == '.') continue;
                cons.insert(mp[P(ni,nj)]);
            }
            int c2 = c - cons.size() + 1;
            ans += mint(c2)/mint(red);
        }
    }
    cout << ans.val() << endl;
    return 0;
}