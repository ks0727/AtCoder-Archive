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
                int now = 1001001001;
                int cnt = 0;
                int c = 0;
                while(true){
                    if(j >= w-k) break;
                    if(cnt >= k){
                        if(s[i][j] == 'o' && s[i][j-k] == '.') now--;
                        else if(s[i][j] == '.' && s[i][j-k] == 'o') now++;
                        ans = min(ans,now);
                    }
                    if(s[i][j] == 'x') break;
                    if(cnt == k) now = k - c;
                    if(s[i][j] == 'o' && cnt < k) c++;
                    j++;
                    cnt++;
                }
                cout << cnt << endl;
            }
        }
    };
    auto col = [&](vector<string> s){
        rep(j,w){
            rep(i,h-k){
                if(s[i][j] == 'x') continue;
                int now = 1001001001;
                int cnt = 0;
                int c = 0;
                while(true){
                    if(i >= h-k) break;
                    if(cnt >= k){
                        if(s[i][j] == 'o' && s[i-k][j] == '.') now--;
                        else if(s[i][j] == '.' && s[i-k][j] == 'o') now++;
                        ans = min(ans,now);
                    }
                    if(s[i][j] == 'x') break;
                    if(cnt == k) now = k - c;
                    if(s[i][j] == 'o' && cnt < k) c++;
                    i++;
                    cnt++;
                }
                cout << cnt << endl;
            }
        }
    };
    row(s);
    col(s);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}