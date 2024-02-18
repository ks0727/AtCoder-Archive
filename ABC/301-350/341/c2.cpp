#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    auto f = [&](int i,int j){
        int ni = i, nj = j;
        rep(ti,t.size()){
            if(t[ti] == 'U') ni--;
            else if(t[ti] == 'D') ni++;
            else if(t[ti] == 'R') nj++;
            else if(t[ti] == 'L') nj--;
            if(ni < 0 || nj < 0 || ni >= h-1 || nj >= w-1) return false;
            if(s[ni][nj] == '#') return false;
        }
        return true;
    };
    int ans = 0;
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            if(s[i][j] == '#') continue;
            if(f(i,j)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}