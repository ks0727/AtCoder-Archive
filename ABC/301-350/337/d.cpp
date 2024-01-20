#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    const int INF = 1001001001;
    int ans = INF;
    auto row = [&](vector<string> s){
        rep(i,h){
            rep(j,w-k){
                if(s[i][j] == 'x') continue;
                int nj = j;
                int now = 0;
                int cnt = 0;
                while(true){
                    if(nj == j + k){
                        ans = min(ans,now);
                        break;
                    }
                    if(s[i][nj] == 'x') break;
                    if(s[i][nj] == '.') now++;
                    nj++;
                }
            }
        }
    };
    auto col = [&](vector<string> s){
        rep(j,w){
            rep(i,h-k){
                if(s[i][j] == 'x') continue;
                int ni = i;
                int now = 0;
                while(true){
                    if(ni == i + k){
                        ans = min(ans,now);
                        break;
                    }
                    if(s[ni][j] == 'x') break;
                    if(s[ni][j] == '.') now++;
                    ni++;
                }
            }
        }
    };
    row(s);
    col(s);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}