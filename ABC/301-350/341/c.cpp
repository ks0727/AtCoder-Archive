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
    int ans = 0;
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            bool ok = true;
            if(s[i][j] == '#') continue;
            int ni = i, nj = j;
            for(auto c : t){
                if(c == 'U') ni--;
                else if(c == 'D') ni++;
                else if(c == 'L') nj--;
                else if(c == 'R') nj++;
                if(s[ni][nj] == '#'){
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}