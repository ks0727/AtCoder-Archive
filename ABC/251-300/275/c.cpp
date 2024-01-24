#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

bool ingrid(int ni, int nj){
    if(ni < 0 || nj < 0 || ni >= 9 || nj >= 9) return false;
    return true;
}

bool square(vector<string> s, P now, int di, int dj){
    auto [i,j] = now;
    if(!ingrid(i+di,j+dj)) return false;
    if(s[i+di][j+dj] != '#') return false;
    if(!ingrid(i+di+dj,j+dj-di)) return false;
    if(s[i+di+dj][j+dj-di] != '#') return false;
    if(!ingrid(i+dj,j-di)) return false;
    if(s[i+dj][j-di] != '#') return false;
    return true;
}

int main(){
    vector<string> s(9);
    rep(i,9) cin >> s[i];
    int ans = 0;
    rep(j,9){
        rep(i,9){
            if(s[i][j] != '#') continue;
            rep(di,10){
                for(int dj=1;dj<=(10);dj++){
                    if(square(s,P(i,j),di,dj)) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}