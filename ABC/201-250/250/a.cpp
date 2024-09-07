#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int di[] = {1,0,-1,0};
int dj[] = {0,-1,0,1};

int main(){
    int h,w;
    cin >> h >> w;
    int r,c;
    cin >> r >> c;
    r--; c--;
    int ans = 0;
    rep(d,4){
        int ni = r+di[d]; int nj = c+dj[d];
        if(ni == h || nj == w || ni < 0 || nj < 0) continue;
        ans++;
    }   
    cout << ans << endl;
    return 0;
}