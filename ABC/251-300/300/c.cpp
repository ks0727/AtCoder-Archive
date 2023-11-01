#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h)rep(j,w) cin >> c[i][j];
    vector<vector<bool> > seen(w,vector<bool>(h));
    int n = min(h,w);
    vector<int> ans(n);
    rep(i,h-1){
        rep(j,w-1){
            if(seen[i][j]) continue;
            if(c[i][j] == '#'){
                seen[i][j] = true;
                int ny = i;
                int nx = j;
                int cnt = 0;
                while(1){
                    nx++; ny++;
                    if(nx > w || nx < 0 || ny > h || ny < 0) break;
                    if(c[ny][nx] == '.') break;
                    seen[ny][nx] = true;
                    cnt++;
                }
                nx--; ny --;
                if(cnt < 2) continue;
                int mid_x = (j+nx)/2;
                int mid_y = (i+ny)/2;
                for(int k = 1; k <= cnt/2;k++){
                    mid_x += 1; mid_y -=1 ;
                    if(mid_x > w || mid_y < 0) break;
                    seen[mid_y][mid_x] = true;
                }
                mid_x = (j+nx)/2;
                mid_y = (i+ny)/2;
                for(int k = 1; k <= cnt/2;k++){
                    mid_x -= 1; mid_y +=1;
                    if(mid_x < 0 || mid_y > h) break;
                    seen[mid_y][mid_x] = true;
                }
                ans[cnt/2-1]++;
            }
        }
    }
    rep(i,n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}