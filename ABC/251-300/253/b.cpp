#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int si=-1,sj=-1,gi=-1,gj=-1;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'o' && si == -1 && sj == -1){
            si = i; sj = j;
        }
        if(s[i][j] == 'o' && si != -1){
            gi = i; gj = j;
        }
    }
    int ans = abs(si - gi) + abs(sj - gj);
    cout << ans << endl;
    return 0;
}