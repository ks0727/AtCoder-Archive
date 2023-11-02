#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    queue<P> q;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            q.push({i,j});
            while(!q.empty()){
                P pos = q.front(); q.pop();
                rep(xi,h){
                    rep(yj,w){
                        if(max(abs(pos.first-xi),abs(pos.second-yj)) == 1){
                            if(s[xi][yj] == '#' && make_pair(xi,yj) != make_pair(i,j)){
                                s[xi][yj] = '.';
                                q.push({xi,yj});
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#') ans++;
    }
    cout << ans << endl;
    return 0;
}