#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int di[] = {1,-1,1,1};
const int dj[] = {-1,1,-1,1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int n = min(h,w);
    vector<int> ans(n+1);
    rep(i,h)rep(j,w){
        if(s[i][j] != '#') continue;
        int cnt = 0;
        rep(v,4){
            int ni = i+di[v],nj = j+dj[v];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(s[ni][nj] == '#') cnt++;
        }
        if(cnt == 4){
            int l = 0;
            int ni = i,nj=j;
            while(1){
                ni++; nj++;
                if(ni == h || nj == w) break;
                if(s[ni][nj] != '#') break;
                l++;
            }
            ans[l]++;
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}