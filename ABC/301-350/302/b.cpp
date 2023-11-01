#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
const int dx[] = {1,1,0,-1,-1,-1,0,1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};


int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<P> s_pos;
    rep(i,h){
        rep(j,w){
            if(s[i][j] != 's') continue;
            s_pos.push_back({i,j});
        }
    }

    string nuke = "uke";
    vector<P> ans;
    for(auto pos : s_pos){
        vector<vector<bool> > seen(h,vector<bool>(w));
        int i = pos.first;
        int j = pos.second;
        ans.push_back({i+1,j+1});
        rep(d,8){
            int ni = i + dx[d], nj = j + dy[d];
            if(ni >= w || ni < 0 || nj >= h || nj < 0) continue;
                if(s[ni][nj] == 'n'){
                    ans.push_back({ni+1,nj+1});
                    rep(k,3){
                        ni += dx[d]; nj += dy[d];
                        if(ni > w || ni < 0 || nj > h || nj < 0) break;
                        if(s[ni][nj] != nuke[k]){
                            ans.erase(ans.end()-k-1,ans.end());
                            break;
                        } 
                        ans.push_back({ni+1,nj+1});
                    }
                }
                if(d == 7 && ans.size() < 5){
                    ans.clear();
                }
                else continue;
            }
        }
    rep(i,ans.size()){
        cout << ans[i].first << ' '<< ans[i].second << endl;
    }
    return 0;
}