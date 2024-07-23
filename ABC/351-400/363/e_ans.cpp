#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int h,w,y;
    cin >> h >> w >> y;
    vector<vector<P> > ps(y);
    rep(i,h)rep(j,w){
        int a;
        cin >> a;
        if(a <= y) ps[a-1].emplace_back(i+1,j+1); //番兵を作るために+1する
    }
    vector<vector<bool> > remain(h+2,vector<bool>(w+2));
    vector<vector<bool> > under(h+2,vector<bool>(w+2,true));
    rep(i,h)rep(j,w){
        remain[i+1][j+1] = true;
        under[i+1][j+1] = false;
    }
    int ans = h*w;

    rep(year,y){
        queue<P> q;
        for(auto[i,j] : ps[year]){
            under[i][j] = true;
            bool sink = false;
            rep(v,4){
                int ni = i +di[v]; int nj = j+dj[v];
                if(!remain[ni][nj]) sink = true;
            }
            if(sink){
                remain[i][j] = false;
                q.emplace(i,j);
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            rep(v,4){
                int ni = i +di[v]; int nj = j+dj[v];
                if(under[ni][nj] && remain[ni][nj]){
                    remain[ni][nj] = false;
                    q.emplace(ni,nj);
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}