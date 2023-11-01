#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

vector<int> dx = {1,0};
vector<int> dy = {0,1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> > a(h,vector<int>(w));
    set<int> st;
    rep(i,h)rep(j,w) cin >> a[i][j];
    int ans = 0;
    auto dfs = [&](auto f, int x ,int y)->void{
        if(x >= w || y >= h) return;
        if(st.count(a[x][y])) return;
        if(x == w-1 && y == h-1){
            ans++;
            return;
        }
        st.insert(a[x][y]);
        rep(d,2){
            int nx = x+dx[d]; int ny = y+dy[d];
            f(f,nx,ny);
        }
        st.erase(a[x][y]);
    };
    //P initial = {0,0};
    dfs(dfs,0,0);
    cout << ans << endl;
    return 0;
}